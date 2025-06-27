#include <alsa/asoundlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

// WAV文件头结构
typedef struct {
    char     chunk_id[4];     // "RIFF"
    int      chunk_size;      // 文件总长度 - 8
    char     format[4];       // "WAVE"
    
    char     subchunk1_id[4]; // "fmt "
    int      subchunk1_size;  // 16 (PCM格式)
    short    audio_format;    // 1 (PCM)
    short    num_channels;    // 声道数
    int      sample_rate;     // 采样率
    int      byte_rate;       // 每秒字节数
    short    block_align;     // 每个样本的字节数
    short    bits_per_sample; // 位深度
    
    char     subchunk2_id[4]; // "data"
    int      subchunk2_size;  // 音频数据长度
} WavHeader;

// 获取当前时间（毫秒级精度）
double get_current_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

int main() {
    // ALSA设备参数
    const char *device = "default";
    snd_pcm_t *capture_handle;
    snd_pcm_hw_params_t *hw_params;
    int err;
    
    // 音频参数
    unsigned int sample_rate = 44100;   // 44.1 kHz
    int channels = 2;                   // 立体声
    snd_pcm_uframes_t frames = 1024;    // 每周期帧数
    int bits_per_sample = 16;           // 16位采样
    
    // 计算录制时间（5秒）
    const int duration_sec = 5;
    const double duration_ms = duration_sec * 1000.0;  // 转换为毫秒
    const size_t total_frames = sample_rate * duration_sec;
    const size_t buffer_size = frames * channels * (bits_per_sample / 8);
    
    // 打开PCM设备
    if ((err = snd_pcm_open(&capture_handle, device, SND_PCM_STREAM_CAPTURE, 0)) < 0) {
        fprintf(stderr, "无法打开设备: %s\n", snd_strerror(err));
        return 1;
    }
    
    // 分配硬件参数结构
    if ((err = snd_pcm_hw_params_malloc(&hw_params)) < 0) {
        fprintf(stderr, "无法分配参数: %s\n", snd_strerror(err));
        return 1;
    }
    
    // 初始化参数
    if ((err = snd_pcm_hw_params_any(capture_handle, hw_params)) < 0) {
        fprintf(stderr, "无法初始化参数: %s\n", snd_strerror(err));
        return 1;
    }
    
    // 设置参数：交错模式
    if ((err = snd_pcm_hw_params_set_access(capture_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
        fprintf(stderr, "无法设置访问模式: %s\n", snd_strerror(err));
        return 1;
    }
    
    // 设置采样格式
    snd_pcm_format_t format = SND_PCM_FORMAT_S16_LE;
    if ((err = snd_pcm_hw_params_set_format(capture_handle, hw_params, format)) < 0) {
        fprintf(stderr, "无法设置格式: %s\n", snd_strerror(err));
        return 1;
    }
    
    // 设置声道数
    if ((err = snd_pcm_hw_params_set_channels(capture_handle, hw_params, channels)) < 0) {
        fprintf(stderr, "无法设置声道数: %s\n", snd_strerror(err));
        return 1;
    }
    
    // 设置采样率
    unsigned int actual_rate = sample_rate;
    if ((err = snd_pcm_hw_params_set_rate_near(capture_handle, hw_params, &actual_rate, 0)) < 0) {
        fprintf(stderr, "无法设置采样率: %s\n", snd_strerror(err));
        return 1;
    }
    if (actual_rate != sample_rate) {
        fprintf(stderr, "警告：实际采样率 %u Hz (请求 %u Hz)\n", actual_rate, sample_rate);
    }
    
    // 设置周期大小
    if ((err = snd_pcm_hw_params_set_period_size_near(capture_handle, hw_params, &frames, 0)) < 0) {
        fprintf(stderr, "无法设置周期大小: %s\n", snd_strerror(err));
        return 1;
    }
    
    // 应用参数
    if ((err = snd_pcm_hw_params(capture_handle, hw_params)) < 0) {
        fprintf(stderr, "无法应用参数: %s\n", snd_strerror(err));
        return 1;
    }
    
    // 释放参数结构
    snd_pcm_hw_params_free(hw_params);
    
    // 准备设备
    if ((err = snd_pcm_prepare(capture_handle)) < 0) {
        fprintf(stderr, "无法准备设备: %s\n", snd_strerror(err));
        return 1;
    }
    
    // 创建输出文件
    FILE *wav_file = fopen("recording.wav", "wb");
    if (!wav_file) {
        perror("无法创建WAV文件");
        return 1;
    }
    
    // 预留WAV文件头位置
    WavHeader header;
    memset(&header, 0, sizeof(header));
    fwrite(&header, 1, sizeof(header), wav_file);
    
    // 分配音频缓冲区
    char *buffer = malloc(buffer_size);
    if (!buffer) {
        perror("内存分配失败");
        return 1;
    }
    
    // 录制音频（改进时间显示逻辑）
    size_t frames_recorded = 0;
    double start_time_ms = get_current_time_ms();  // 录制开始时间
    printf("开始录制...\n");

    while (frames_recorded < total_frames) {
        // 计算已录制时间（毫秒）
        double current_time_ms = get_current_time_ms();
        double elapsed_ms = current_time_ms - start_time_ms;
        double remaining_ms = duration_ms - elapsed_ms;

        double remain_time = remaining_ms / 1000.0;
        if (remain_time < 0.0) {
            remain_time = 0.0;
        }
        
        // 显示倒计时（格式：剩余时间 秒.毫秒）
        printf("\r剩余时间: %5.3lf秒", remain_time);
        fflush(stdout);

        // 从设备读取数据（保持不变）
        snd_pcm_uframes_t frames_to_read = frames;
        if (frames_recorded + frames_to_read > total_frames) {
            frames_to_read = total_frames - frames_recorded;
        }

        if ((err = snd_pcm_readi(capture_handle, buffer, frames_to_read)) != frames_to_read) {
            fprintf(stderr, "读取错误: %s\n", snd_strerror(err));
            break;
        }

        // 写入文件（保持不变）
        size_t bytes_to_write = frames_to_read * channels * (bits_per_sample / 8);
        fwrite(buffer, 1, bytes_to_write, wav_file);
        frames_recorded += frames_to_read;
    }
    
    printf("\n录制完成\n");
    
    // 填充WAV文件头
    size_t data_size = frames_recorded * channels * (bits_per_sample / 8);
    
    memcpy(header.chunk_id, "RIFF", 4);
    header.chunk_size = 36 + data_size;
    memcpy(header.format, "WAVE", 4);
    
    memcpy(header.subchunk1_id, "fmt ", 4);
    header.subchunk1_size = 16;
    header.audio_format = 1; // PCM
    header.num_channels = channels;
    header.sample_rate = sample_rate;
    header.byte_rate = sample_rate * channels * (bits_per_sample / 8);
    header.block_align = channels * (bits_per_sample / 8);
    header.bits_per_sample = bits_per_sample;
    
    memcpy(header.subchunk2_id, "data", 4);
    header.subchunk2_size = data_size;
    
    // 重写文件头
    fseek(wav_file, 0, SEEK_SET);
    fwrite(&header, 1, sizeof(header), wav_file);
    
    // 清理资源
    fclose(wav_file);
    free(buffer);
    snd_pcm_close(capture_handle);
    
    printf("文件已保存为 recording.wav\n");
    return 0;
}