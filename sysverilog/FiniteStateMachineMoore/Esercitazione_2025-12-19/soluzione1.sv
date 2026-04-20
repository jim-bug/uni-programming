/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2025-12-19
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

module fsm_moore_uscita_trasparente_ritardata (
    input  logic clk,
    input  logic reset,
    input  logic x,
    output logic y
);

    typedef enum logic {CHIUSA, APERTA} statetype;
    statetype state, nextstate;

    always_ff @(posedge clk, posedge reset) begin
        if (reset)
            state <= CHIUSA;
        else
            state <= nextstate;
    end

    // Lo stato memorizza il valore campionato di x al fronte precedente.
    always_comb begin
        nextstate = (x == 1'b1) ? APERTA : CHIUSA;
    end

    // Se al fronte precedente x era 1 (stato APERTA), y segue x durante il ciclo corrente.
    always_comb begin
        if (state == APERTA)
            y = x;
        else
            y = 1'b0;
    end

endmodule
