
[bits 32]
section .data
	rand: dd 0
	seed: dd 0
	k: dd 0xABCDEFEF
	output: db "%x",0
	
section .text
	extern __time32
	extern _exit
	extern _printf
	extern _getchar

	
	global _main
	_main:
		push DWORD seed
		call __time32
		add esp,4
		repeta:
			mov eax,[seed]
			and eax,0x00ffff00
			shr eax,8
			mov [rand],eax
			mul eax
			add eax,[k]
			mov [seed],eax
			push DWORD [seed]
			push DWORD output
		call _printf
		add esp,8
			call _getchar
			cmp eax,'A'
			jne repeta
		call _exit
		ret