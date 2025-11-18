// testbench of temp.sv

module example();

    logic a,b,c,y;
    example dut(a,b,c,y);

    initial begin
        a=0; b=1; c=1; #10;
        $display("a: %b, b: %b, c: %c, y: %b", a,b,c,y);
    end

endmodule
