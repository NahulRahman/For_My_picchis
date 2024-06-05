; https://www.youtube.com/playlist?list=PL8XrlqjNe73_5k670fJDqYtSg7I9-WlWq
; https://www.youtube.com/watch?v=1TCtk2cwAbY

.MODEL SMALL
.STACK 100H
.CODE 
MAIN PROC
    MOV BX,1
    MOV CX,8
    
    L1:
    PUSH CX 
    MOV CX,BX ;REMOVE THIOS LINE FOR RIGHT SIDED REVERSE PYRAMID 
    MOV AH,2
    MOV DL,'*'
    
   L2:
    INT 21H      
    
    LOOP L2
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    INC BX
    POP CX
    LOOP L1
    
    
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN