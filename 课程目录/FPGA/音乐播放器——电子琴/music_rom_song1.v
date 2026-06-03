// ================================================================
// Module: music_rom_song1
// Function: song1 note ROM initialized from music_DATA.mif.
// ================================================================
module music_rom_song1 (
    addr,
    note,
    song_len
);
    input [10:0] addr;
    output [3:0] note;
    output [10:0] song_len;
	 
	 // 至少要囊括音乐大小
    reg [3:0] mem [0:255] /* synthesis ram_init_file="music_DATA.mif" */;

    assign song_len = 11'd136;// 改音乐要根据音乐最后一个音的位置减一填写，下面一行的也是
    assign note = (addr < 11'd136) ? mem[addr] : 4'd0;
endmodule
