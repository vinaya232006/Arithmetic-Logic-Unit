// tb_alu.v
`timescale 1ns / 1ps

module tb_ALU;

reg [3:0] A, B;
reg [2:0] ALU_Sel;
wire [3:0] ALU_Out;
wire CarryOut;

ALU uut (
    .A(A),
    .B(B),
    .ALU_Sel(ALU_Sel),
    .ALU_Out(ALU_Out),
    .CarryOut(CarryOut)
);

initial begin
    // Monitor values
    $monitor("A = %b, B = %b, ALU_Sel = %b, ALU_Out = %b, CarryOut = %b", A, B, ALU_Sel, ALU_Out, CarryOut);

    // Test addition
    A = 4'b0101; B = 4'b0011; ALU_Sel = 3'b000; #10;
    
    // Test subtraction
    A = 4'b0110; B = 4'b0010; ALU_Sel = 3'b001; #10;
    
    // Test AND
    A = 4'b1100; B = 4'b1010; ALU_Sel = 3'b010; #10;
    
    // Test OR
    A = 4'b1100; B = 4'b1010; ALU_Sel = 3'b011; #10;

    // Test NOT
    A = 4'b1100; ALU_Sel = 3'b100; #10;

    $finish;
end

endmodule
