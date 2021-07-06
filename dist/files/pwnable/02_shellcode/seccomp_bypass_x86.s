global main
extern set_seccomp

section .text
main:
BITS 64
	call set_seccomp

	lea rax, [rel $ + 0x11]
	push rax
	mov dword [rsp+4], 0x23
	retf

BITS 32
	lea esp, [stack + 0x100]
	and esp, 0xfffffff8

	mov eax, 4		; sys_write (32 bit)
	mov ebx, 1
	lea ecx, [msg]
	mov edx, 14
	int 0x80

	push 0x33
	call $+5
	add dword [esp], 0x5
	retf

BITS 64
	mov rax, 0x3c		; sys_exit (64 bit)
	syscall

section .data
msg db "Hello, World!", 0x0a, 0x00

section .bss
stack resb 0x100
