; WRITE A COUNT-CONTROLLED LOOP TO DISPLAY A ROW OF 80 STARS.
; https://github.com/Mashpy/assembly_program/blob/master/14%20DISPLAY%20A%20ROW%20OF%2080%20STARS.txt


.MODEL SMALL
.STACK 100H
.DATA
.CODE
 MAIN PROC
 MOV CX,80
 MOV AH,2
 MOV DL,'*'

TOP:
INT 21H
LOOP TOP
MOV AH,4CH
INT 21H  

MAIN ENDP
END MAIN