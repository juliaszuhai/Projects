section .data
a: dd 1, -10, 5, 2, 5, 0, -9, 17
len: equ ($-a)/4
rez: dd 0
format: db '%d',0
extern _printf
section .text
global _main
_main:
mov ebx,0
mov eax,0
mov esi,0
cattimp:
cmp [a+esi*4],ebx
jg maimare
neg DWORD [a+esi*4]
add eax,[a+esi*4]
jmp sari
maimare: add eax,[a+esi*4]
sari:
inc esi
cmp esi,len
jb cattimp
mov [rez],eax
push DWORD [rez]
push DWORD format
call _printf
add esp,8
ret