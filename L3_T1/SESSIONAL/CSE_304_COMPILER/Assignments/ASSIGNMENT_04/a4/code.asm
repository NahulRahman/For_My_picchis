MOV AX, 10
MOV [a], AX


MOV AX, 5
MOV [c], AX


MOV AX, c
MOV BX, 2
MUL BX
MOV [t1], AX


MOV AX, a
MOV BX, t1
ADD AX, BX
MOV [t2], AX


MOV AX, t2
MOV BX, 12
SUB AX, BX
MOV [t3], AX


MOV AX, t3
MOV [d], AX


MOV AX, a
MOV BX, c
SUB AX, BX
MOV [t4], AX


MOV AX, 2
MOV BX, 3
SUB AX, BX
MOV [t5], AX


MOV AX, t5
MOV BX, 5
MUL BX
MOV [t6], AX


MOV AX, t4
MOV BX, t6
SUB AX, BX
MOV [t7], AX


MOV AX, t7
MOV [d], AX


