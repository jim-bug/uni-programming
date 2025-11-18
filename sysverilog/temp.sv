/*

*/

// input/output: utilizzato per definire la direzione della porta (ingresso/uscita)
// logic: definisce il tipo di porta (booleana, in questo caso)
module example(input logic a, b, c, output logic y);
    assign y = ~a & ~b & ~c | a & ~b & ~c | a & ~b & c;   
endmodule

module and3(input logic a, b, c, output logic y);
    assign y = a & b & c;   
endmodule

module inv(input logic a, output logic y);
    assign y = ~a;   
endmodule

module nand3(input logic a, b, c, output logic y);
    logic n1;
    and3 andgate(a, b, c, n1);
    inv inverter(n1, y);   
endmodule


