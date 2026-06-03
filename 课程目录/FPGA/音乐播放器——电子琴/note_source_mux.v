// ================================================================
// 模块名：note_source_mux
// 作用：选择当前真正送去发声的音符来源。
//
// 新手理解：
// - 平时播放 song_note，也就是 ROM 乐谱里的音符。
// - 当矩阵键盘有按键按下 key_valid=1 时，临时用 key_note 覆盖歌曲音符，
//   相当于电子琴手动弹奏优先。
//
// 接线说明（外部/内部）：
// - 外部接线：无。本模块只在内部选择“自动播放”还是“矩阵键盘弹奏”。
// - 内部连线：song_note 接 song_select_mux.song_note；
//             key_valid 接 matrix_keyboard_scan.key_valid；
//             key_note 接 keyboard_note_map.key_note；
//             note_out 接 note_decoder.note_in。
// ================================================================
module note_source_mux (
    song_note,
    key_valid,
    key_note,
    note_out
);
    input [3:0] song_note;
    input key_valid;
    input [3:0] key_note;
    output [3:0] note_out;

    // 键盘优先级高于自动播放。
    assign note_out = key_valid ? key_note : song_note;
endmodule

