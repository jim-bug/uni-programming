/*
Gli operatori bitwise operano bit per bit su vettori di bit (BUS).
Gli operatori bitwise principali sono:

1) &  - bitwise AND
2) |  - bitwise OR
3) ^  - bitwise XOR
4) ~& - bitwise NAND
5) ~| - bitwise NOR
6) ~^ - bitwise XNOR

*/

// [MSB:LSB]: Dichiarazione di un BUS a MSB+1 bit
module bitwise_operators(input logic [3:0] a, b, output logic [3:0] y1, y2, y3, y4, y5);

    assign y1 = a & b;   // bitwise AND
    assign y2 = a | b;   // bitwise OR
    assign y3 = a ^ b;   // bitwise XOR
    assign y4 = ~(a & b); // bitwise NAND
    assign y5 = ~(a | b); // bitwise NOR

endmodule

// Operatori di riduzione
module and8(input logic [7:0] a, output logic y);
    
    // Per usare un operatori di riduzione si pone davanti al vettore l'operatore desiderato.
    // Semplifica: assign y = a[0] & a[1] & a[2] & a[3] & a[4] & a[5] & a[6] & a[7];
    assign y = &a; // riduzione AND
    
endmodule

// Costrutto selettivo con operatore ternario:
module mux2(input logic [3:0] d0, d1, input logic sel, output logic [3:0] y);

    assign y = sel ? d1 : d0; // if sel==1 (True) then y=d1 else y=d0, ternary operator

endmodule


// Le costanti numeriche in SystemVerlog vengono scritte nel seguente formato: N'Bvalue (N: Numero di bit, B: base):
// Le basi possibili sono:
// B = b  -> binario
// B = o  -> ottale
// B = d  -> decimale
// B = h  -> esadecimale

