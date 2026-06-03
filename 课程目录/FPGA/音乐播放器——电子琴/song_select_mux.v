// ================================================================
// Module: song_select_mux
// Function: select one of four song ROM outputs.
// Song mapping: 0=song0, 1=song1, 2=song2, 3=song3.
// ================================================================
module song_select_mux (
    song_id,
    note0,
    note1,
    note2,
    note3,
    len0,
    len1,
    len2,
    len3,
    song_note,
    song_len
);
    input [1:0] song_id;
    input [3:0] note0;
    input [3:0] note1;
    input [3:0] note2;
    input [3:0] note3;
    input [10:0] len0;
    input [10:0] len1;
    input [10:0] len2;
    input [10:0] len3;
    output [3:0] song_note;
    output [10:0] song_len;

    reg [3:0] song_note_r;
    reg [10:0] song_len_r;

    assign song_note = song_note_r;
    assign song_len = song_len_r;

    always @(song_id or note0 or note1 or note2 or note3 or len0 or len1 or len2 or len3) begin
        case (song_id)
            2'd0: begin song_note_r = note0; song_len_r = len0; end
            2'd1: begin song_note_r = note1; song_len_r = len1; end
            2'd2: begin song_note_r = note2; song_len_r = len2; end
            2'd3: begin song_note_r = note3; song_len_r = len3; end
            default: begin song_note_r = note0; song_len_r = len0; end
        endcase
    end
endmodule
