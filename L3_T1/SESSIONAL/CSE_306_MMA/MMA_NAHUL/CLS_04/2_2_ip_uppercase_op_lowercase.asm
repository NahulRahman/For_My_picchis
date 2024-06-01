; Assembly Program to input a capital letter from user and convert it into small letter (uppercase to lowercase)
; https://tshahab.com/assembly-language/convert-uppercase-to-lowercase-and-vice-versa/



dosseg             ; Tells the assembler to use the DOS segment addressing mode
.model small       ; Sets the memory model to "small"
.stack 100h        ; Sets the size of the program stack to 256 bytes (100h in hexadecimal)
.data              ; Indicates the start of the data segment
.code              ; Indicates the start of the code segment

main proc          ; Starts the "main" procedure

mov ah, 1          ; Move the value 1 into the AH register (AH is used for input/output operations)
int 21h            ; Call the DOS interrupt 21h, which prints the character in the AL register (ASCII code 1 is "SOH")

mov dl, al         ; Move the value in the AL register (which was set by the interrupt) into the DL register (which is used for input/output operations)
add dl, 32         ; Add 32 to the value in the DL register (which converts a lowercase letter to uppercase in ASCII)
mov ah, 2          ; Move the value 2 into the AH register (which indicates the "print character" function)
int 21h            ; Call the DOS interrupt 21h, which prints the character in the DL register (which is now the uppercase version of the character printed earlier)

mov ah, 4ch        ; Move the value 4Ch into the AH register (which indicates the "terminate with return code" function)
int 21h            ; Call the DOS interrupt 21h, which terminates the program with the return code in the AL register

main endp          ; Ends the "main" procedure

end main           ; Indicates the end of the program