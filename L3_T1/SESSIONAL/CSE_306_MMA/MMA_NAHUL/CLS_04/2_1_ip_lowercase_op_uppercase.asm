; https://tshahab.com/assembly-language/convert-uppercase-to-lowercase-and-vice-versa/

.model small
.stack 100h
.data
.code

main proc

mov ah, 1
int 21h

mov dl, al
sub dl, 32         ; Subtract 32 from the value in the DL register (which converts an uppercase letter to lowercase in ASCII)
mov ah, 2
int 21h

mov ah, 4ch        
int 21h


main endp
end main