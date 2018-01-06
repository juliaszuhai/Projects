;suma a doua numere citite din fisier
assume ds:data,cs:code
data segment

filename db 'f.txt',0
buffer db 6 dup (?),'$'
zece dw 10
nou dw 0
handle dw ?
s db 6 dup (?),'$'

data ends
code segment
start:
mov ax,data
mov ds,ax

;open file
mov ah,3dh
mov al,2
mov dx,offset filename
int 21h

mov handle,ax
;read forom file

goOn:
	mov ah,3fh
	mov bx,handle
	mov cx,6
	mov dx,offset buffer
	int 21h

	mov si,ax
	mov buffer[si],'$'

	mov ax,0
	mov di,0
	mov dx,0
	repeat:	
		sub buffer[di],'0'
		mul zece
		mov bl,buffer[di]
		mov bh,0
		add ax,bx
		inc di
		cmp di,5
		je obtain
		jmp repeat

	obtain:
		add nou,ax
		mov dx,0
		mov ax,nou
		mov cx,0
	cmp si,6
	je goOn

stiva:	
	div zece
	push dx
	mov dx,0
	inc cx
	cmp ax,0
	mov si,0
	je scoate
	jmp stiva

scoate:
	pop dx
	mov s[si],dl
	add s[si],'0'
	inc si
	loop scoate

mov s[si],'$'
mov ah,40h
mov bx,handle
mov cx,si
mov dx,offset s
int 21h
	

		









mov ax,4c00h
int 21h
code ends
end start