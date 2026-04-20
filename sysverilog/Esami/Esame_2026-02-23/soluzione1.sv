/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2026-02-23
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

module fsm_moore_contatore_bidirezionale_saturo_0_4 (
    input  logic       clk,
    input  logic       reset,
    input  logic       x,
    output logic [2:0] y
);

    typedef enum logic [2:0] {S0, S1, S2, S3, S4} statetype;
    statetype state, nextstate;

    always_ff @(posedge clk, posedge reset) begin
        if (reset)
            state <= S0;
        else
            state <= nextstate;
    end

    always_comb begin
        nextstate = state;

        case (state)
            S0: nextstate = (x == 1'b0) ? S1 : S0;
            S1: nextstate = (x == 1'b0) ? S2 : S0;
            S2: nextstate = (x == 1'b0) ? S3 : S1;
            S3: nextstate = (x == 1'b0) ? S4 : S2;
            S4: nextstate = (x == 1'b0) ? S4 : S3;
            default: nextstate = S0;
        endcase
    end

    always_comb begin
        case (state)
            S0: y = 3'd0;
            S1: y = 3'd1;
            S2: y = 3'd2;
            S3: y = 3'd3;
            S4: y = 3'd4;
            default: y = 3'd0;
        endcase
    end

endmodule
