section .data
n1: dd 12
n2: dd 30
rez: dd 0
format: db '%d',0
extern _printf
section .text
global _main
_main:
mov eax,[n1]
mov ecx,[n2]
add eax,ecx
mov [rez],eax
push DWORD [rez]
push DWORD format
call _printf
add esp,8
ret
