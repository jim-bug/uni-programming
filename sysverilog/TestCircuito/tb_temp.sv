/*
Autore: Ignazio Leonardo Calogero Sperandeo
Data: 18/11/2025
Consegna: Scrivere il testbench di temp.sv

by jim-bug // :)
*/

module tb_temp;
    logic a, b, c, y;

    temp dut(
        .a(a),
        .b(b),
	.c(c),
        .y(y)
    );

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_temp);

        $display(" t | a b c | y");
        $monitor("%2t | %0b %0b %0b | %0b", $time, a, b, c, y);

	a=0; b=0; c=0; #10;
	a=0; b=0; c=1; #10;
	a=0; b=1; c=0; #10;
	a=0; b=1; c=1; #10;
	a=1; b=0; c=0; #10;
	a=1; b=0; c=1; #10;
	a=1; b=1; c=0; #10;
	a=1; b=1; c=1; #10;


        #10;
        $finish;
    end
endmodule
