assume ds:data,cs:code

data segment
sir dw 12a4h,5b7fh
len equ ($-sir)/2
saispe dw 16
tabhexa db '0123456789abcdef'
public tabhexa
public saispe
data ends
code segment
extrn afisare: proc
start:
mov ax,data
mov ds,ax

mov di,len
mov si, offset sir
while:
	lodsw
	call far ptr afisare
	dec di
	cmp di,0
	je sari
	jmp while
sari:

mov ax,4c00h
int 21h
code ends
end start