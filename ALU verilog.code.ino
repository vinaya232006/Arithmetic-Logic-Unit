// alu.v
module ALU (
    input [3:0] A,       // 4-bit input A
    input [3:0] B,       // 4-bit input B
    input [2:0] ALU_Sel, // Operation select signal
    output reg [3:0] ALU_Out,
    output reg CarryOut
);

always @(*) begin
    case (ALU_Sel)
        3'b000: {CarryOut, ALU_Out} = A + B;         // Addition
        3'b001: {CarryOut, ALU_Out} = A - B;         // Subtraction
        3'b010: ALU_Out = A & B;                     // AND
        3'b011: ALU_Out = A | B;                     // OR
        3'b100: ALU_Out = ~A;                        // NOT A
        default: ALU_Out = 4'b0000;
    endcase
end

endmodule
