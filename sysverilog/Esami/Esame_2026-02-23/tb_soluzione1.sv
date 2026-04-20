/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2026-02-23
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

`timescale 1ns/1ns

module tb_fsm_moore_contatore_bidirezionale_saturo_0_4();
    logic clk, reset, x;
    logic [2:0] y;

    fsm_moore_contatore_bidirezionale_saturo_0_4 dut (.*);

    always begin
        clk = 1'b0; #5;
        clk = 1'b1; #5;
    end

    initial begin
        $dumpfile("dump_moore.vcd");
        $dumpvars(0, tb_fsm_moore_contatore_bidirezionale_saturo_0_4);

        $monitor("Time: %4t | Reset: %b | X: %b | State: %s | Y: %0d",
                 $time, reset, x, dut.state.name(), y);

        x = 1'b0;
        reset = 1'b1; #12;
        reset = 1'b0;

        // Sale fino a saturazione a 4 (x=0), poi scende fino a saturazione a 0 (x=1)
        x = 1'b0; #10;
        x = 1'b0; #10;
        x = 1'b0; #10;
        x = 1'b0; #10;
        x = 1'b0; #10;
        x = 1'b1; #10;
        x = 1'b1; #10;
        x = 1'b1; #10;
        x = 1'b1; #10;
        x = 1'b1; #10;

        #20;
        $finish;
    end

endmodule
