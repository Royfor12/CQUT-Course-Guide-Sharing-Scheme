// ================================================================
// Module: music_rom_song3
// Function: song3 note ROM initialized from song3_wohewodezuguo_DATA.mif.
// ================================================================
module music_rom_song3 (
    addr,
    note,
    song_len
);
    input [10:0] addr;
    output [3:0] note;
    output [10:0] song_len;

	 // 至少要囊括音乐大小
    reg [3:0] mem [0:511] /* synthesis ram_init_file="song3_wohewodezuguo_DATA.mif" */;

    assign song_len = 11'd456;// 改音乐要根据音乐最后一个音的位置减一填写，下面一行的也是
    assign note = (addr < 11'd456) ? mem[addr] : 4'd0;
endmodule
