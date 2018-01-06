;citire din fisier nr in baza 16 + scriere in fisier baza 10

assume cs:code, ds:data

data segment
filename db 'f.txt',0
buffer db 5 dup (?),'$'
zece dw 10
saispe dw 16
s db 6 dup (?)
handler dw ?
nou dw 0
c dw 3
p dw ?
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

;read file
mov handler,ax
mov ah,3fh
mov bx,handler
mov cx,5
mov dx,offset buffer
int 21h

mov si,ax
mov buffer[si],'$'

;transf din string adica din hexa in nr decimal
mov si,0
repeat:
	jmp litere
	aici:
	sub buffer[si],'0'
	acolo:
	mov dx,0 ;facem doubleword
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
	cmp si,3
	je iasa1
	jmp repeat
litere:
	cmp buffer[si],'A'
	je zec
	cmp buffer[si],'B'
	je unspe
	cmp buffer[si],'C'
	je doispe
	cmp buffer[si],'D'
	je treispe
	cmp buffer[si],'E'
	je paispe
	cmp buffer[si],'F'
	je cinspe
jmp aici
zec: 
	mov buffer[si],10
	jmp acolo
unspe: 
	mov buffer[si],11
	jmp acolo
doispe: 
	mov buffer[si],12
	jmp acolo
treispe: 
	mov buffer[si],13
	jmp acolo
paispe: 
	mov buffer[si],14
	jmp acolo
cinspe: 
	mov buffer[si],15
	jmp acolo
iasa1:
	cmp buffer[si],'A'
	je zec2
	cmp buffer[si],'B'
	je unspe2
	cmp buffer[si],'C'
	je doispe2
	cmp buffer[si],'D'
	je treispe2
	cmp buffer[si],'E'
	je paispe2
	cmp buffer[si],'F'
	je cinspe2
	sub buffer[si],'0'
	nu:
	mov bl,buffer[si]
	mov bh,0
	add nou,bx
	mov dx,0 ;facem doubleword
	mov ax,nou
	mov cx,0
jmp iasa2
zec2: 
	mov buffer[si],10
	jmp nu
unspe2: 
	mov buffer[si],11
	jmp nu
doispe2: 
	mov buffer[si],12
	jmp nu
treispe2: 
	mov buffer[si],13
	jmp nu
paispe2: 
	mov buffer[si],14
	jmp nu
cinspe2: 
	mov buffer[si],15
	jmp nu
iasa2:
	div zece
	mov bx,dx
	push bx
	mov dx,0
	inc cx
	mov si,0
	cmp ax,0
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
mov bx,handler
mov cx,si
mov dx,offset s
int 21h
jmp sf

sf:
mov ax,4c00h
int 21h
code ends
end start