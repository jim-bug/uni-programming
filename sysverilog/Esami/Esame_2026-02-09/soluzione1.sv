/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2026-02-09
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

module fsm_moore_conteggio_uno_ultimi_due_bit (
    input  logic       clk,
    input  logic       reset,
    input  logic       x,
    output logic [1:0] y
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

    always_comb begin
        case (state)
            S00: y = 2'd0;
            S01: y = 2'd1;
            S10: y = 2'd1;
            S11: y = 2'd2;
            default: y = 2'd0;
        endcase
    end

endmodule
