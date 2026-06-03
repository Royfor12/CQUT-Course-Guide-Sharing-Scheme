// ================================================================
// 模块名：key_debounce_pulse
// 作用：把机械按键的抖动信号整理成稳定电平和单周期按下脉冲。
//
// 新手理解：
// - 普通按键按下/松开瞬间会抖动，FPGA 会误以为按了很多次。
// - 本模块先用两个触发器同步异步输入，再等待输入稳定一段时间。
// - key_level 表示“按键当前是否按下”；key_press_pulse 只在刚按下时为 1 个 clk。
//
// 接线说明（外部/内部）：
// - 外部接线：key_n 接 1 个低有效轻触按键，未按=1，按下=0。
//             本工程需要例化 3 个本模块：
//             KEY1=PIN_J9  -> 下一首/切歌；
//             KEY2=PIN_K14 -> 播放；
//             KEY3=PIN_J11 -> 暂停。
// - 内部连线：clk/rst_n 接系统时钟和内部复位；
//             三个实例的 key_press_pulse 分别接 player_control 的
//             key_next_pulse/key_play_pulse/key_pause_pulse；
//             key_level 只有需要持续按住状态时才接，其余可悬空不用。
// - 参数提醒：DEBOUNCE_CNT_MAX 默认按 12 MHz 约 20 ms，换时钟时建议重算。
// ================================================================
module key_debounce_pulse (
    clk,
    rst_n,
    key_n,
    key_level,
    key_press_pulse
);
    parameter DEBOUNCE_CNT_MAX = 20'd240000;

    input clk;
    input rst_n;
    input key_n;
    output key_level;
    output key_press_pulse;

    reg key_sync0;
    reg key_sync1;
    reg key_stable_n;
    reg key_level_r;
    reg key_level_d;
    reg [19:0] debounce_cnt;

    assign key_level = key_level_r;
    assign key_press_pulse = key_level_r & ~key_level_d;

    // 两级同步，降低外部按键异步输入带来的亚稳态风险。
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            key_sync0 <= 1'b1;
            key_sync1 <= 1'b1;
        end else begin
            key_sync0 <= key_n;
            key_sync1 <= key_sync0;
        end
    end

    // 输入与稳定值不同并持续足够久后，才承认按键状态真的改变。
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            key_stable_n <= 1'b1;
            key_level_r <= 1'b0;
            key_level_d <= 1'b0;
            debounce_cnt <= 20'd0;
        end else begin
            key_level_d <= key_level_r;

            if (key_sync1 == key_stable_n) begin
                debounce_cnt <= 20'd0;
            end else if (debounce_cnt >= DEBOUNCE_CNT_MAX) begin
                key_stable_n <= key_sync1;
                key_level_r <= ~key_sync1;
                debounce_cnt <= 20'd0;
            end else begin
                debounce_cnt <= debounce_cnt + 20'd1;
            end
        end
    end
endmodule

