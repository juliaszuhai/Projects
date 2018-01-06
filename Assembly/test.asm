assume ds:data,cs:code
data segment

filename db 'f.txt',0
buffer db 17 dup (?)
handle dw 0

nou dw 0
nr dw 0
doi dw 2
zece dw 10

data ends
code segment
start:
mov ax,data
mov ds,ax

;primul numar
mov cx,0
repeta:	
	mov ah,01h
	int 21h
	cmp al,' '
	je scoate
	inc cx
	jmp obtain

obtain:
	mov bl,al
	sub bl,'0'
	mov bh,0
	mov ax,nou
	mul zece
	mov nou,ax
	add nou,bx
	jmp repeta

scoate:
;al doilea numar
mov cx,0
repeta2:	
	mov ah,01h
	int 21h
	cmp al,' '
	je scoate2
	inc cx
	jmp obtain2

obtain2:
	mov bl,al
	sub bl,'0'
	mov bh,0
	mov ax,nr
	mul zece
	mov nr,ax
	add nr,bx
	jmp repeta2

;am terminat de citit ambele numere

scoate2:
	mov ax,nou
	add ax,nr
	mov nr,ax
	mov cx,0
	;deschidem fisierul in modul write
	mov ah,3Dh
	mov al,1
	mov dx,offset filename
	int 21h

	mov handle,ax
	mov dx,0
	mov ax,nr
	repeat:		
		div doi
		mov bx,dx
		push bx
		mov dx,0
		cmp ax,0
		je aici1
		inc cx
		jmp repeat

aici1:	
	mov si,0
	inc cx
aici2:
	pop bx
	mov buffer[si],bl
	add buffer[si],'0'
	inc si
	
loop aici2
mov buffer[si],'$'

afis:
	mov ah,40h
	mov bx,handle
	mov cx,si
	mov dx,offset buffer
	int 21h
	
	
		


	
mov ax,4c00h
int 21h
code ends
end start