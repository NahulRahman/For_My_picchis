; home task, c for capital, l for lower and n for number, nested if else loop

.MODEL SMALL
.STACK 100H
.DATA 
msg1 db "Capital Letters : $"
msg2 db 0AH, 0DH, "Small letters   : $"
msg3 db 0AH, 0DH, "Numeric Chars   : $"

.code
main proc
    
    mov ax, @data
    mov ds, ax
    mov ah, 09H
    LEA dx, msg1
    int 21H
    
    mov ah, 02H
    mov dl, 41H
    mov cx,26
    
    L1:
        int 21H
        inc dl
        LOOP L1 
    
    
    
    mov ax, @data
    mov ds, ax
    mov ah, 09H
    LEA dx, msg2
    int 21H
    
    mov ah, 02H
    mov dl, 61H
    mov cx,26
    
    L2:
        int 21H
        inc dl
        LOOP L2 
        
        
   
    mov ax, @data
    mov ds, ax
    mov ah, 09H
    LEA dx, msg3
    int 21H
    
    mov ah, 02H
    mov dl, 30H
    mov cx, 10
    
    L3:
        int 21H
        inc dl
        LOOP L3      
        



main endp
end main