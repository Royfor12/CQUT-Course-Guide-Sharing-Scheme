// ================================================================
// 模块名：keyboard_note_map
// 作用：把 4x4 矩阵键盘编号转换成音符编号。
//
// 音符约定：
// - 0 表示休止/不发声。
// - 1~7 表示低/中音区的 1~7。
// - 8~14 表示高音区的 1~7。
// - 15 在 note_decoder 中映射为更高一级的 1。
//
// 接线说明（外部/内部）：
// - 外部接线：无。本模块只处理矩阵键盘扫描后的内部编号。
// - 内部连线：key_valid 接 matrix_keyboard_scan.key_valid；
//             key_code 接 matrix_keyboard_scan.key_code；
//             key_note 接 note_source_mux.key_note。
// ================================================================
module keyboard_note_map (
    key_valid,
    key_code,
    key_note
);
    input key_valid;
    input [3:0] key_code;
    output [3:0] key_note;

    reg [3:0] key_note_r;

    assign key_note = key_note_r;

    // 没有有效按键时输出 0，避免键盘通道误发音。
    always @(key_valid or key_code) begin
        if (!key_valid) begin
            key_note_r = 4'd0;
        end else begin
            case (key_code)
                4'd0: key_note_r = 4'd1;
                4'd1: key_note_r = 4'd2;
                4'd2: key_note_r = 4'd3;
                4'd3: key_note_r = 4'd4;
                4'd4: key_note_r = 4'd5;
                4'd5: key_note_r = 4'd6;
                4'd6: key_note_r = 4'd7;
                4'd7: key_note_r = 4'd0;
                4'd8: key_note_r = 4'd8;
                4'd9: key_note_r = 4'd9;
                4'd10: key_note_r = 4'd10;
                4'd11: key_note_r = 4'd11;
                4'd12: key_note_r = 4'd12;
                4'd13: key_note_r = 4'd13;
                4'd14: key_note_r = 4'd14;
                4'd15: key_note_r = 4'd0;
                default: key_note_r = 4'd0;
            endcase
        end
    end
endmodule

