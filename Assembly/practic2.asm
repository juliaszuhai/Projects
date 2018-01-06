;cititm dintr-un fisier cateva nr pe 2 biti si sa se afiseze in consola care dintre ele sunt prime
assume ds:data,cs:code
data segment
	
	filename db 'f.txt',0
	buffer db 2 dup (?),'$'
	nr db ?
	doi db 2
	msgEste db 'Este prim','$'
	msgNu db 'Nu este prim','$'
	d db ?
	ok db ?

	
data ends
code segment
Prim proc
	mov al,nr
	mov ah,0
	div doi
	mov cl,al
	mov ok,1
	
	repeat:
		mov al,nr
		mov ah,0
		cmp cl,1
		je eprim
		div cl
		cmp ah,0
		je nueprim
		
	loop repeat
	cmp ok,1
	je eprim
	
	eprim:
		mov ah,9
		mov dx,offset msgEste
		int 21h
		jmp sari
	nueprim:
		mov ah,9
		mov dx,offset msgNu
		int 21h
	sari:
	ret
	Prim endp

start:
mov ax,data
mov ds,ax

; open the file using function 3dh of the interrupt 21h
	mov ah, 3dh
	mov al, 0 	; open the file for reading 
	mov dx, offset filename
	int 21h
	
	mov bx, ax 
	goOn:	
		mov ah,3fh
		mov dx,offset buffer
		mov cx,3
		int 21h
		
		
		mov si,ax
		mov buffer[si],'$'
		
		obtain: 
			sub buffer[0],'0'
			mov al,buffer[0]
			mul doi
			mov nr,al
			sub buffer[1],'0'
			mov dl,buffer[1]
			add dl,nr
			mov nr,dl
		
		pr0:
				cmp nr,0
				je goOn
				
		pr1:
				cmp nr,1
				je goOn
			
			
		afis:
			mov ah,02h
			mov dl,nr
			add dl,'0'
			int 21h
			call Prim
			
		cmp si,3	
		je goOn
		
		
		




mov ax,4c00h
int 21h
code ends
end start
