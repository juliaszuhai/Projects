section .data
a: dd 12
b: dd 30
rez: dd 0
format: db '%d',0
extern _printf
section .text
global _main
_main:
mov eax,[a]
mov ebx,[b]
cattimp:
cmp eax,ebx
ja amaimare
jb bmaimare
amaimare: sub eax,ebx
			jmp sari
bmaimare: sub ebx,eax
sari:
cmp eax,ebx
jnz cattimp
mov [rez],eax
push DWORD [rez]
push DWORD format
call _printf
add esp,8
ret