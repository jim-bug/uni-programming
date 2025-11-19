
/*
Autore: Ignazio Leonardo Calogero Sperandeo
Data: 18/11/2025
Consegna: Implementare l'esempio proposto a lezione. 
*/

module temp (
    input  logic a,
    input  logic b,
    input  logic c,
    output logic y
);
    assign y = ~a & ~b & ~c | a & ~b & ~c | a & ~b & c;
endmodule
