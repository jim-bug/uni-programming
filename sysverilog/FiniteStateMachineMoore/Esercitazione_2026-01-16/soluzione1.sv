/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2026-01-16
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

module fsm_moore_parita_ultimi_tre_bit (
    input  logic clk,
    input  logic reset,
    input  logic x,
    output logic y
);

    typedef enum logic [2:0] {
        S000, S001, S010, S011,
        S100, S101, S110, S111
    } statetype;
    statetype state, nextstate;

    always_ff @(posedge clk, posedge reset) begin
        if (reset)
            state <= S000;
        else
            state <= nextstate;
    end

    always_comb begin
        nextstate = state;

        case (state)
            S000: nextstate = (x == 1'b0) ? S000 : S001;
            S001: nextstate = (x == 1'b0) ? S010 : S011;
            S010: nextstate = (x == 1'b0) ? S100 : S101;
            S011: nextstate = (x == 1'b0) ? S110 : S111;
            S100: nextstate = (x == 1'b0) ? S000 : S001;
            S101: nextstate = (x == 1'b0) ? S010 : S011;
            S110: nextstate = (x == 1'b0) ? S100 : S101;
            S111: nextstate = (x == 1'b0) ? S110 : S111;
            default: nextstate = S000;
        endcase
    end

    // Uscita a 0 se negli ultimi 3 bit ci sono esattamente due '1': 011, 101, 110.
    assign y = (state == S011 || state == S101 || state == S110) ? 1'b0 : 1'b1;

endmodule
