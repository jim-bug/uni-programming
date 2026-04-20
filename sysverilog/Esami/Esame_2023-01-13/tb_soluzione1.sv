/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2023-01-13
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

`timescale 1ns/1ns

module tb_fsm_moore_rilevatore_sequenza_011();
    logic clk, reset, x, y;

    fsm_moore_rilevatore_sequenza_011 dut (.*);

    always begin
        clk = 1'b0; #5;
        clk = 1'b1; #5;
    end

    initial begin
        $dumpfile("dump_moore.vcd");
        $dumpvars(0, tb_fsm_moore_rilevatore_sequenza_011);

        $monitor("Time: %4t | Reset: %b | X: %b | State: %s | Y: %b",
                 $time, reset, x, dut.state.name(), y);

        x = 1'b0;
        reset = 1'b1; #12;
        reset = 1'b0;

        // Sequenza con piu' occorrenze di 011: 0 1 1 0 1 1 1 0 1 0
        x = 1'b0; #10;
        x = 1'b1; #10;
        x = 1'b1; #10;
        x = 1'b0; #10;
        x = 1'b1; #10;
        x = 1'b1; #10;
        x = 1'b1; #10;
        x = 1'b0; #10;
        x = 1'b1; #10;
        x = 1'b0; #10;

        #20;
        $finish;
    end

endmodule
