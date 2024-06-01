;READ AN ALPHABET CHARACTER FROM KEYBOARD AND DISPLAY AT BEGINING OF NEXT LINE   
;https://deeprajbhujel.blogspot.com/2015/10/8086-single-character-input-and-display.html

.MODEL SMALL  
.STACK 100H  
.DATA  

.CODE
MAIN PROC
    
MOV AH,1    ;asks for keyboard input.
INT 21H                       ;stored in AL register.
MOV DL,AL                ;DL is the register used to display
MOV AH,2                   ;character output function
INT 21H


CODE ENDS
END
