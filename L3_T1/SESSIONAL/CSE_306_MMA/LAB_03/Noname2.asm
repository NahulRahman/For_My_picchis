Code Segment
Assume CS:Code,DS:Code,SS:Code,ES:Code
ORG 1000H

PA EQU 18H
PB EQU 1AH
PC EQU 1CH
CR EQU 1EH

MOV AL,10000000b
OUT CR,AL
;MOV AL,0FFH
OUT PA,AL
OUT PB,AL
OUT PC,AL
L1:
;MOV CX,5000H
MOV AL,11111110b
L2:
OUT PA,AL
MOV CX,5000H

D:
LOOP D
ROL AL,1
JC L2
JMP L1
;A1:
;MOV SI,OFFSET Patt
;MOV AL,[SI]
;MOV AL,0FEH
;OUT PA,AL
;LOOP A1
;STC

;INC SI
;MOV AL,[SI]
;OUT PA,AL
;OUT PB,AL

;INC SI
;MOV AL,[SI]
;OUT PB,AL
;LOOP A1


;MOV AL,0FFH
;OUT PA,AL
;OUT PB,AL
;MOV CX,9000H
;D: LOOP D
;JMP AA



;Patt DB 0FEH,11100111b,7FH

CODE ENDS
END