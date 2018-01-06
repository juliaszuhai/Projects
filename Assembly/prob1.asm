assume ds:data,cs:code
data segment
	s db 'abcdaf'
	voc db 'a'
	len equ $-s
	d db len dup(?)
data ends
code segment
start:
mov ax,data
mov ds,ax
mov es,ax

lea si,s
lea di,d
mov bx,0
mov cx,len
repeta:
	mov al,voc
	cmp al,s[si]
	je altfel
	add bx,1
	inc(si)
	cmp si,len
	jb repeta
	altfel:
	mov al,voc 
	mov d[bx],al
	add bx,1
	inc(si)
	cmp si,len
	jb repeta
	



mov ax,4c00h
int 21h
code ends
end start



