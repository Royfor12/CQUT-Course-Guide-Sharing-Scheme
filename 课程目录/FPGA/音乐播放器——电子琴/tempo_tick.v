// ================================================================
// 模块名：tempo_tick
// 作用：产生“乐谱前进一步”的节拍脉冲。
//
// 新手理解：
// - FPGA 的 clk 很快，如果每个 clk 都读下一个音符，音乐会快到听不清。
// - 本模块把高速时钟分频成很慢的 tick；tick 只在一个 clk 周期内为 1。
// - music_addr_counter 看到 tick=1 时，才把乐谱地址加 1。
//
// 接线说明（外部/内部）：
// - 外部接线：speed_sw 接 1 个拨码开关。按底板/核心板图，推荐接 SW1=PIN_J2；
//             0=慢速 SLOW_HZ，1=快速 FAST_HZ。
// - 内部连线：clk 接工程系统时钟；rst_n 接内部复位信号或固定 1'b1；
//             tick 接 music_addr_counter.tick，不需要接到板外。
// - 参数提醒：CLK_HZ 默认按 12 MHz 写，若系统时钟不是 12 MHz，要同步修改。
// ================================================================
module tempo_tick (
    clk,
    rst_n,
    speed_sw,
    tick
);
    parameter CLK_HZ = 12000000;
    parameter SLOW_HZ = 4;
    parameter FAST_HZ = 10;

    input clk;
    input rst_n;
    input speed_sw;
    output tick;

    reg tick_r;
    reg [31:0] cnt;
    wire [31:0] limit;

    // 根据 speed_sw 选择每秒产生多少个 tick。
    assign limit = speed_sw ? (CLK_HZ / SLOW_HZ) : (CLK_HZ / FAST_HZ);
    assign tick = tick_r;

    // 计数到 limit-1 时输出一个周期的 tick 脉冲，然后重新计数。
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cnt <= 32'd0;
            tick_r <= 1'b0;
        end else begin
            if (cnt >= limit - 1) begin
                cnt <= 32'd0;
                tick_r <= 1'b1;
            end else begin
                cnt <= cnt + 32'd1;
                tick_r <= 1'b0;
            end
        end
    end
endmodule

