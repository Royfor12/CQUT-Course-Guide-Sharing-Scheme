// ================================================================
// 模块名：music_addr_counter
// 作用：歌曲 ROM 地址计数器。
//
// 新手理解：
// - addr 指向当前正在播放的乐谱位置。
// - tick 来一次，addr 才前进一步，所以音乐速度由 tempo_tick 决定。
// - 到达 song_len 末尾后自动回到 0，实现循环播放。
//
// 接线说明（外部/内部）：
// - 外部接线：无。本模块是歌曲地址内部计数器。
// - 内部连线：clk/rst_n 接系统时钟和内部复位；
//             tick 接 tempo_tick.tick；
//             play_en 接 player_control.play_en；
//             clear 接 player_control.song_clear；
//             song_len 接 song_select_mux.song_len；
//             addr 同时接 music_rom_song0.addr 和 music_rom_song1.addr。
// ================================================================
module music_addr_counter (
    clk,
    rst_n,
    tick,
    play_en,
    clear,
    song_len,
    addr
);
    input clk;
    input rst_n;
    input tick;
    input play_en;
    input clear;
    input [10:0] song_len;
    output [10:0] addr;

    reg [10:0] addr_r;

    assign addr = addr_r;

    // 只有 play_en=1 且收到 tick 时才换到下一个音符。
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            addr_r <= 11'd0;
        end else if (clear) begin
            addr_r <= 11'd0;
        end else if (play_en && tick) begin
            if (song_len <= 11'd1) begin
                addr_r <= 11'd0;
            end else if (addr_r >= song_len - 11'd1) begin
                addr_r <= 11'd0;
            end else begin
                addr_r <= addr_r + 11'd1;
            end
        end
    end
endmodule

