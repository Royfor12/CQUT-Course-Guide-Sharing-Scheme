// ================================================================
// 模块名：note_decoder
// 作用：把 4 位音符编号转换成数码管显示码、高音标志和蜂鸣器装载值。
//
// 新手理解：
// - note_in=0 表示休止符，tone_reload=11'h7ff，speaker_driver 会静音。
// - note_in=1~7 显示 1~7，high=0。
// - note_in=8~14 仍显示 1~7，但 high=1，表示高音区。
// - tone_reload 是给 speaker_driver 的计数初值，不是直接的频率值。
//
// 接线说明（外部/内部）：
// - 外部接线：无。本模块只做内部音符译码。
// - 内部连线：note_in 接 note_source_mux.note_out；
//             code 可接 DECL7S.seg_data_1，用于显示 1~7；
//             high 可接内部高音指示信号，若不用 LED 可不接到板外；
//             tone_reload 接 speaker_driver.tone_reload 或旧版 SPKER.TN。
// ================================================================
module note_decoder (
    note_in,
    code,
    high,
    tone_reload
);
    input [3:0] note_in;
    output [3:0] code;
    output high;
    output [10:0] tone_reload;

    reg [3:0] code_r;
    reg high_r;
    reg [10:0] tone_reload_r;

    assign code = code_r;
    assign high = high_r;
    assign tone_reload = tone_reload_r;

    // 查表译码：同一个音符编号同时决定显示内容、是否高音、蜂鸣器音高。
    always @(note_in) begin
        case (note_in)
            4'd0: begin tone_reload_r = 11'h7ff; code_r = 4'd0; high_r = 1'b0; end
            4'd1: begin tone_reload_r = 11'h305; code_r = 4'd1; high_r = 1'b0; end
            4'd2: begin tone_reload_r = 11'h390; code_r = 4'd2; high_r = 1'b0; end
            4'd3: begin tone_reload_r = 11'h40c; code_r = 4'd3; high_r = 1'b0; end
            4'd4: begin tone_reload_r = 11'h45c; code_r = 4'd4; high_r = 1'b0; end
            4'd5: begin tone_reload_r = 11'h4ad; code_r = 4'd5; high_r = 1'b0; end
            4'd6: begin tone_reload_r = 11'h50a; code_r = 4'd6; high_r = 1'b0; end
            4'd7: begin tone_reload_r = 11'h55c; code_r = 4'd7; high_r = 1'b0; end
            4'd8: begin tone_reload_r = 11'h582; code_r = 4'd1; high_r = 1'b1; end
            4'd9: begin tone_reload_r = 11'h5c8; code_r = 4'd2; high_r = 1'b1; end
            4'd10: begin tone_reload_r = 11'h606; code_r = 4'd3; high_r = 1'b1; end
            4'd11: begin tone_reload_r = 11'h640; code_r = 4'd4; high_r = 1'b1; end
            4'd12: begin tone_reload_r = 11'h656; code_r = 4'd5; high_r = 1'b1; end
            4'd13: begin tone_reload_r = 11'h684; code_r = 4'd6; high_r = 1'b1; end
            4'd14: begin tone_reload_r = 11'h69a; code_r = 4'd7; high_r = 1'b1; end
            4'd15: begin tone_reload_r = 11'h6c0; code_r = 4'd1; high_r = 1'b1; end
            default: begin tone_reload_r = 11'h7ff; code_r = 4'd0; high_r = 1'b0; end
        endcase
    end
endmodule

