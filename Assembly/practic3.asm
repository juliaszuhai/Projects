;You have a string of words s dw ‘12’,’34’,’56’,’78’. Output into a file the string in reverse order (‘87654321’).

assume ds:data,cs:code
data segment
	s dw ‘12’,’34’,’56’,’78’
	len equ $-s
	filename db 'f.txt',0
	buffer db 20 dup (?),'$'
	
data ends
code segment
mov ax,data
mov ds,ax
mov es,ax
std
mov bx,0
	repeta:
		lodsw
		mov buffer[bx],al
		inc(bx)



mov ax,4c00h
int 21h
code ends
end start
