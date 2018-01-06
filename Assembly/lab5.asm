section .data
filename: db "f.txt",0
nFile: dd 0

section .text

%include "msdn_defs.inc"
extern CreateFile 
global _main
_main:
push NULL
push FILE_ATTRIBUTE_NORMAL
PUSH OPEN_EXISTING
PUSH NULL
PUSH FILE_SHARE_READ
PUSH GENERIC_READ 
push filename
call CreateFile
mov [nFile],eax
ret

