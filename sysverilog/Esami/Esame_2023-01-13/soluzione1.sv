/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2023-01-13
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

module fsm_moore_rilevatore_sequenza_011 (
    input  logic clk,
    input  logic reset,
    input  logic x,
    output logic y
);

    typedef enum logic [1:0] {
        S0, // nessun prefisso utile
        S1, // ultimo bit utile: 0
        S2, // ultimi bit utili: 01
        S3  // rilevato 011
    } statetype;
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
            S1: nextstate = (x == 1'b0) ? S1 : S2;
            S2: nextstate = (x == 1'b0) ? S1 : S3;
            S3: nextstate = (x == 1'b0) ? S1 : S0;
            default: nextstate = S0;
        endcase
    end

    assign y = (state == S3) ? 1'b0 : 1'b1;

endmodule
