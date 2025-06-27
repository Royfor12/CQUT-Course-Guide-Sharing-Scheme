#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <alsa/asoundlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>

// 全局标志用于优雅退出
volatile sig_atomic_t stop_playback = 0;

// 处理Ctrl+C信号
void handle_sigint(int sig) {
    stop_playback = 1;
}

// WAV文件头结构体
typedef struct {
    char     riff[4];        // "RIFF"
    uint32_t file_size;      // 文件总大小-8
    char     wave[4];        // "WAVE"
    char     fmt[4];         // "fmt "
    uint32_t fmt_size;       // fmt chunk大小
    uint16_t audio_format;   // 音频格式 (1=PCM)
    uint16_t num_channels;   // 声道数
    uint32_t sample_rate;    // 采样率
    uint32_t byte_rate;      // 每秒字节数
    uint16_t block_align;    // 每个采样块对齐
    uint16_t bits_per_sample;// 位深度
    char     data[4];        // "data"
    uint32_t data_size;      // 音频数据大小
} WavHeader;

// 打印时间格式 (秒转为 分:秒)
void print_time_format(double seconds) {
    int minutes = (int)seconds / 60;
    int secs = (int)seconds % 60;
    printf("%02d:%02d", minutes, secs);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <wav_file>\n", argv[0]);
        return 1;
    }

    // 注册信号处理
    signal(SIGINT, handle_sigint);

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    // 读取WAV文件头
    WavHeader header;
    if (fread(&header, sizeof(WavHeader), 1, file) != 1) {
        fprintf(stderr, "Failed to read WAV header\n");
        fclose(file);
        return 1;
    }

    // 验证WAV文件格式
    if (memcmp(header.riff, "RIFF", 4) != 0 || 
        memcmp(header.wave, "WAVE", 4) != 0 ||
        memcmp(header.fmt, "fmt ", 4) != 0 ||
        memcmp(header.data, "data", 4) != 0) {
        fprintf(stderr, "Invalid WAV file format\n");
        fclose(file);
        return 1;
    }

    // 只支持PCM格式
    if (header.audio_format != 1) {
        fprintf(stderr, "Only PCM format is supported\n");
        fclose(file);
        return 1;
    }

    // 计算音频时长(秒)
    double duration = (double)header.data_size / header.byte_rate;
    printf("Audio duration: ");
    print_time_format(duration);
    printf("\n");

    // 初始化ALSA
    snd_pcm_t *pcm_handle;
    snd_pcm_hw_params_t *hw_params;
    int err;

    if ((err = snd_pcm_open(&pcm_handle, "default", SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        fprintf(stderr, "Cannot open audio device: %s\n", snd_strerror(err));
        fclose(file);
        return 1;
    }

    if ((err = snd_pcm_hw_params_malloc(&hw_params)) < 0) {
        fprintf(stderr, "Cannot allocate hardware parameter structure: %s\n", snd_strerror(err));
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    if ((err = snd_pcm_hw_params_any(pcm_handle, hw_params)) < 0) {
        fprintf(stderr, "Cannot initialize hardware parameter structure: %s\n", snd_strerror(err));
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_access(pcm_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
        fprintf(stderr, "Cannot set access type: %s\n", snd_strerror(err));
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    snd_pcm_format_t format;
    if (header.bits_per_sample == 8) {
        format = SND_PCM_FORMAT_U8;
    } else if (header.bits_per_sample == 16) {
        format = SND_PCM_FORMAT_S16_LE;
    } else if (header.bits_per_sample == 24) {
        format = SND_PCM_FORMAT_S24_LE;
    } else if (header.bits_per_sample == 32) {
        format = SND_PCM_FORMAT_S32_LE;
    } else {
        fprintf(stderr, "Unsupported bit depth: %d\n", header.bits_per_sample);
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_format(pcm_handle, hw_params, format)) < 0) {
        fprintf(stderr, "Cannot set sample format: %s\n", snd_strerror(err));
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    unsigned int sample_rate = header.sample_rate;
    if ((err = snd_pcm_hw_params_set_rate_near(pcm_handle, hw_params, &sample_rate, 0)) < 0) {
        fprintf(stderr, "Cannot set sample rate: %s\n", snd_strerror(err));
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_channels(pcm_handle, hw_params, header.num_channels)) < 0) {
        fprintf(stderr, "Cannot set channel count: %s\n", snd_strerror(err));
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    // 设置缓冲区大小和周期
    snd_pcm_uframes_t buffer_size = 4096;
    snd_pcm_uframes_t period_size = 1024;
    snd_pcm_hw_params_set_buffer_size_near(pcm_handle, hw_params, &buffer_size);
    snd_pcm_hw_params_set_period_size_near(pcm_handle, hw_params, &period_size, 0);

    if ((err = snd_pcm_hw_params(pcm_handle, hw_params)) < 0) {
        fprintf(stderr, "Cannot set parameters: %s\n", snd_strerror(err));
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    snd_pcm_hw_params_free(hw_params);

    if ((err = snd_pcm_prepare(pcm_handle)) < 0) {
        fprintf(stderr, "Cannot prepare audio interface for use: %s\n", snd_strerror(err));
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    // 设置缓冲区大小
    size_t buffer_size_bytes = period_size * header.block_align;
    char *buffer = malloc(buffer_size_bytes);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        snd_pcm_close(pcm_handle);
        fclose(file);
        return 1;
    }

    size_t total_bytes_read = 0;
    struct timespec start_time, current_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    printf("Playing... (Press Ctrl+C to stop)\n");

    while (!stop_playback && total_bytes_read < header.data_size) {
        size_t bytes_to_read = buffer_size_bytes;
        if (total_bytes_read + bytes_to_read > header.data_size) {
            bytes_to_read = header.data_size - total_bytes_read;
        }

        size_t bytes_read = fread(buffer, 1, bytes_to_read, file);
        if (bytes_read <= 0) {
            break; // 文件结束或读取错误
        }

        total_bytes_read += bytes_read;

        // 获取当前时间并计算已播放时间
        clock_gettime(CLOCK_MONOTONIC, &current_time);
        double elapsed_time = (current_time.tv_sec - start_time.tv_sec) + 
                            (current_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;
        
        // 显示当前播放时间
        printf("\rCurrent time: ");
        print_time_format(elapsed_time);
        printf(" / ");
        print_time_format(duration);
        fflush(stdout);

        // 写入ALSA设备
        snd_pcm_sframes_t frames = snd_pcm_writei(pcm_handle, buffer, bytes_read / header.block_align);
        if (frames < 0) {
            frames = snd_pcm_recover(pcm_handle, frames, 0);
        }
        if (frames < 0) {
            fprintf(stderr, "\nWrite error: %s\n", snd_strerror(frames));
            break;
        }
    }

    if (stop_playback) {
        printf("\nPlayback interrupted\n");
    } else {
        // 显示最终时间
        clock_gettime(CLOCK_MONOTONIC, &current_time);
        double elapsed_time = (current_time.tv_sec - start_time.tv_sec) + 
                            (current_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;
        printf("\rCurrent time: ");
        print_time_format(elapsed_time > duration ? duration : elapsed_time);
        printf(" / ");
        print_time_format(duration);
        printf("\nPlayback finished.\n");
    }

    // 等待所有播放完毕
    snd_pcm_drain(pcm_handle);
    snd_pcm_close(pcm_handle);
    fclose(file);
    free(buffer);

    return 0;
}