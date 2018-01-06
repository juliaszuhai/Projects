assume ds:data,cs:code
data segment

filename db 'f.txt',0
buffer db 5 dup (?),'$'
saispe dw 16
s db 5 dup (?)
nou dw 0
handle dw ?
c dw 4
p dw ?
zece db 10
 

data ends

code segment
start:
mov ax,data
mov ds,ax

;open file
mov ah,3Dh
mov al,2
mov dx,offset filename
int 21h

;read filename
mov bx,ax
mov handle,bx
mov ah,3fh
mov cx,5
mov dx,offset buffer
int 21h


mov si,ax
mov buffer[si],'$'

;transformam din string hexa in numar decimal
mov si,0
repeat:
	

	sub buffer[si],'0'
	mov dx,0
	mov ax,1
	mov cx,c
	putere:
		mul saispe
	loop putere
	dec c
	mov p,ax
	mov al,buffer[si]
	mov ah,0
	mul p
	add nou,ax
	inc si
	cmp si,16
	je iasa1
	jmp repeat
iasa1:

	mov dx,0
	mov ax,nou
	div doi
	mov cx,0
iasa2:
	div zece
	mov bl,ah
	mov bh,0
	push bx
	mov ah,0
	inc cx
	mov si,0
	cmp al,0
	je scoate
	jmp iasa2

scoate:
	pop bx
	add bl,'0'
	mov s[si],bl
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
