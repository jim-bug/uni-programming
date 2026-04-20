/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2025-12-19
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

`timescale 1ns/1ns

module tb_fsm_moore_uscita_trasparente_ritardata();
    logic clk, reset, x, y;

    fsm_moore_uscita_trasparente_ritardata dut (.*);

    always begin
        clk = 1'b0; #5;
        clk = 1'b1; #5;
    end

    initial begin
        $dumpfile("dump_moore.vcd");
        $dumpvars(0, tb_fsm_moore_uscita_trasparente_ritardata);

        $monitor("Time: %4t | Reset: %b | X: %b | State: %s | Y: %b",
                 $time, reset, x, dut.state.name(), y);

        x = 1'b0;
        reset = 1'b1; #12;
        reset = 1'b0;

        // Ciclo 1: x campionato a 1 al fronte -> ciclo successivo y trasparente
        x = 1'b1; #10;

        // Durante stato APERTA, y segue x anche intra-ciclo
        x = 1'b0; #3;
        x = 1'b1; #3;
        x = 1'b0; #4;

        // Campiono 0 al fronte successivo -> stato CHIUSA, y resta 0
        x = 1'b0; #10;
        x = 1'b1; #3;
        x = 1'b0; #7;

        #20;
        $finish;
    end

endmodule
