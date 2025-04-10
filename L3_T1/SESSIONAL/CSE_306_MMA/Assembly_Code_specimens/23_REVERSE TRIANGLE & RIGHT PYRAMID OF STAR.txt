.MODEL SMALL
.STACK 100H
.DATA
STAR DB ?
BLANK DB ?
.CODE 
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
     
    MOV CX,5
    MOV BH,9
    MOV BL,0
    
    MOV STAR,BH
    MOV BLANK,BL
    
    
   L1:
    CMP BLANK,0
    JE L2
    
    MOV AH,2
    MOV DL,32
    INT 21H
    DEC BLANK
   
    JMP L1
    
   L2:
    MOV AH,2
    MOV DL,'*'
    INT 21H
    DEC STAR
    CMP STAR,0
    JNE L2
   
   
  
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    
    
    DEC BH   ;USE JUST ONE INCREMENT FOR PYRAMID
    DEC BH
    MOV STAR,BH
    
    INC BL
    MOV BLANK,BL
    LOOP L1
    
    
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN