;Citire nr de la tastatura si pus in registru/variabila

assume cs:code, ds:data

data segment
	
zece dw 10
nou db 0
nr dw 0

data ends

code segment
start:
mov ax,data
mov ds,ax

mov cx,0
repeat:
	mov ah,1
	int 21h
	cmp al,' '
	jne obtain
	je gata

obtain:
	sub al,'0'
	mov bl,al
	mov bh,0
	mov ax,nr
	mul zece
	mov nr,ax
	add nr,bx
	jmp repeat
gata:
mov ax,4c00h
int 21h
code ends
end start