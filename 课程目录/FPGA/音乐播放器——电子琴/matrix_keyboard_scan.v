// ================================================================
// Module: matrix_keyboard_scan
// Function: scan a 4x4 active-low matrix keyboard.
//
// row_n[3:0] are active-low row inputs with pull-ups.
// col_n[3:0] are active-low column outputs.
// key_valid/key_code are latched, stable outputs for downstream audio logic.
// ================================================================
module matrix_keyboard_scan (
    clk,
    rst_n,
    row_n,
    col_n,
    key_valid,
    key_code
);
    parameter SCAN_DIV_MAX = 16'd12000;

    input clk;
    input rst_n;
    input [3:0] row_n;
    output [3:0] col_n;
    output key_valid;
    output [3:0] key_code;

    reg [15:0] scan_cnt;
    reg [1:0] col_index;
    reg [3:0] col_n_r;
    reg key_valid_r;
    reg [3:0] key_code_r;
    reg any_key_in_round;

    reg scan_hit;
    reg [3:0] scan_code;

    assign col_n = col_n_r;
    assign key_valid = key_valid_r;
    assign key_code = key_code_r;

    always @(col_index) begin
        case (col_index)
            2'd0: col_n_r = 4'b1110;
            2'd1: col_n_r = 4'b1101;
            2'd2: col_n_r = 4'b1011;
            2'd3: col_n_r = 4'b0111;
            default: col_n_r = 4'b1111;
        endcase
    end

    always @(col_index or row_n) begin
        scan_hit = 1'b0;
        scan_code = 4'd0;

        if (!row_n[0]) begin
            scan_hit = 1'b1;
            scan_code = {2'd0, col_index};
        end else if (!row_n[1]) begin
            scan_hit = 1'b1;
            scan_code = {2'd1, col_index};
        end else if (!row_n[2]) begin
            scan_hit = 1'b1;
            scan_code = {2'd2, col_index};
        end else if (!row_n[3]) begin
            scan_hit = 1'b1;
            scan_code = {2'd3, col_index};
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            scan_cnt <= 16'd0;
            col_index <= 2'd0;
            key_valid_r <= 1'b0;
            key_code_r <= 4'd0;
            any_key_in_round <= 1'b0;
        end else if (scan_cnt >= SCAN_DIV_MAX) begin
            scan_cnt <= 16'd0;

            if (scan_hit) begin
                key_valid_r <= 1'b1;
                key_code_r <= scan_code;
            end else if ((col_index == 2'd3) && !any_key_in_round) begin
                key_valid_r <= 1'b0;
                key_code_r <= 4'd0;
            end

            if (col_index == 2'd3) begin
                any_key_in_round <= 1'b0;
            end else if (scan_hit) begin
                any_key_in_round <= 1'b1;
            end

            col_index <= col_index + 2'd1;
        end else begin
            scan_cnt <= scan_cnt + 16'd1;
        end
    end
endmodule
