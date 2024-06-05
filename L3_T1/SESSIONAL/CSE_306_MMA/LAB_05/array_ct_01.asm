; Program to print an array using loop   
; https://codingatharva.blogspot.com/2019/01/program-to-print-array-using-loop-8086.html
.MODEL SMALL
.STACK 100
.DATA
   ARR1 DB '1','2','3','4', '5'
.CODE
   MOV AX , @DATA ; Initialize data segment
   MOV DS , AX
   LEA SI , ARR1 ; Storing base address of array arr1  ; MOV SI , OFFEST ARR1
   MOV CX , 5 ; Initializing counter register to 4
 
  CONT:
    MOV DX , [SI] ; Storing address value at DX
    INC SI         ; Incrementing  SI( Source Index ) memory pointer by 1
    MOV AH , 2  ; Printing DX Contain
    INT 21H
 
   LOOP CONT ; decrement CX by 1 ; If cx == 0 then exit ; else read next number  
 
   MOV AH,4CH
   INT 21H
END