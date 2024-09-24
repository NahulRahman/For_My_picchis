.MODEL SMALL
.STACK 100h

.DATA
a DW 0      ; Declare variable 'a'
c DW 0      ; Declare variable 'c'
t1 DW 0     ; Declare variable 't1'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX   ; Initialize data segment
    
    ; MOV AX, 10
    ; MOV [a], AX
    MOV AX, 10
    MOV a, AX     ; Store 10 in variable 'a'
    
    ; MOV AX, 5
    ; MOV [c], AX
    MOV AX, 5
    MOV c, AX     ; Store 5 in variable 'c'
    
    ; MOV AX, c
    ; MOV BX, 2
    ; ADD AX, BX
    ; MOV [t1], AX
    MOV AX, c     ; Load value of 'c' (5) into AX
    MOV BX, 2     ; Load 2 into BX
    ADD AX, BX    ; Add AX and BX (AX = AX + BX = 5 + 2)
    MOV t1, AX    ; Store the result in 't1'
    
    ; MOV AX, t1
    ; MOV [c], AX
    MOV AX, t1    ; Load the value of 't1' into AX
    MOV c, AX     ; Store the value of 't1' into 'c'

    ; Exit program
    MOV AH, 4CH   ; DOS interrupt to exit the program
    INT 21H

MAIN ENDP
END MAIN
