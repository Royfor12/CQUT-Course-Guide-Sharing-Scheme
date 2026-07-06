// ================================================================
// 模块名：speaker_driver
// 作用：把 note_decoder 给出的音调装载值 tone_reload 转成蜂鸣器方波。
//
// 新手理解：
// - 蜂鸣器听到的是高低电平快速翻转形成的方波。
// - tone_reload 越接近 11'h7ff，计数器越快溢出，输出翻转越快，音调越高。
// - tone_reload=11'h7ff 或 mute=1 时静音。
//
// 接线说明（外部/内部）：
// - 外部接线：spk 接底板蜂鸣器 BEEP。按底板/核心板图，BEEP=PIN_B14。
// - 内部连线：clk_audio 接音频时钟；rst_n 接内部复位信号或固定 1'b1；
//             tone_reload 接 note_decoder.tone_reload；
//             mute 接静音控制，例如自动播放时可由 play_en/key_valid 组合得到。
// ================================================================
module speaker_driver (
    clk_audio,
    rst_n,
    tone_reload,
    mute,
    spk
);
    input clk_audio;
    input rst_n;
    input [10:0] tone_reload;
    input mute;
    output spk;

    reg spk_r;
    reg [10:0] cnt;

    assign spk = spk_r;

    // cnt 从 tone_reload 开始向上数，数到 11'h7ff 时翻转一次 spk。
    always @(posedge clk_audio or negedge rst_n) begin
        if (!rst_n) begin
            cnt <= 11'd0;
            spk_r <= 1'b0;
        end else if (mute || tone_reload == 11'h7ff) begin
            cnt <= tone_reload;
            spk_r <= 1'b0;
        end else if (cnt == 11'h7ff) begin
            cnt <= tone_reload;
            spk_r <= ~spk_r;
        end else begin
            cnt <= cnt + 11'd1;
        end
    end
endmodule

