;citire nr in registru + afisare pe ecran

assume cs:code, ds:data

data segment
	
zece dw 10
		
data ends

code segment
start:
mov ax,data
mov ds,ax


mov dx,0 ;convertim la doubleword
mov ax,65535
mov cx,0
repeat:
	div zece
	mov bx,dx
	push bx
	inc cx
	cmp ax,0
	je continua
	mov dx,0
	jmp repeat
	
continua:
	pop bx
	mov ah,2
	mov dl,bl
	add dl,'0'
	int 21h
loop continua

mov ax,4c00h
int 21h
code ends
end start