// ================================================================
// Module: player_control
// Function: playback state control for play, pause, and song switching.
// ================================================================
module player_control (
    clk,
    rst_n,
    key_next_pulse,
    key_play_pulse,
    key_pause_pulse,
    play_en,
    song_id,
    song_clear
);
    input clk;
    input rst_n;
    input key_next_pulse;
    input key_play_pulse;
    input key_pause_pulse;
    output play_en;
    output [1:0] song_id;
    output song_clear;

    reg play_en_r;
    reg [1:0] song_id_r;
    reg song_clear_r;

    assign play_en = play_en_r;
    assign song_id = song_id_r;
    assign song_clear = song_clear_r;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            play_en_r <= 1'b1;
            song_id_r <= 2'd1;
            song_clear_r <= 1'b1;
        end else begin
            song_clear_r <= 1'b0;

            if (key_next_pulse) begin
                song_id_r <= song_id_r + 2'd1;
                song_clear_r <= 1'b1;
            end

            if (key_play_pulse) begin
                play_en_r <= 1'b1;
            end else if (key_pause_pulse) begin
                play_en_r <= 1'b0;
            end
        end
    end
endmodule
