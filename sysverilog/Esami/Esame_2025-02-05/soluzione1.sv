/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2025-02-05
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

module fsm_moore_ultimi_due_bit_uguali (
    input  logic clk,
    input  logic reset,
    input  logic x,
    output logic y
);

    typedef enum logic [1:0] {S00, S01, S10, S11} statetype;
    statetype state, nextstate;

    always_ff @(posedge clk, posedge reset) begin
        if (reset)
            state <= S00;
        else
            state <= nextstate;
    end

    always_comb begin
        nextstate = state;

        case (state)
            S00: nextstate = (x == 1'b0) ? S00 : S01;
            S01: nextstate = (x == 1'b0) ? S10 : S11;
            S10: nextstate = (x == 1'b0) ? S00 : S01;
            S11: nextstate = (x == 1'b0) ? S10 : S11;
            default: nextstate = S00;
        endcase
    end

    assign y = (state == S00) || (state == S11);

endmodule
