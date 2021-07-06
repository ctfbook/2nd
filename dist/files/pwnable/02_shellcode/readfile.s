BITS 64
global _start

_start:
	lea rdi, [rel fname]	; filename = "/etc/lsb-release"
	xor rsi, rsi		; flags    = O_RDONLY
	mov rax, 0x02		; sys_open
	syscall

	test rax, rax
	js end

	push rax
	push rbp
	mov rbp, rsp
	sub rsp, 0x100

	mov rdi, rax		; fd    = open()
	mov rsi, rsp		; buf   : stack
	mov rdx, 0x100		; count = 0x100
	mov rax, 0x00		; sys_read
	syscall

	mov rdi, 1		; fd    = 1 (STDOUT_FILENO)
	mov rsi, rsp		; buf   : stack
	mov rdx, rax		; count = read()
	mov rax, 0x01		; sys_write
	syscall

	leave

	pop rdi			; fd = open()
	mov rax, 0x03		; sys_close
	syscall

end:
	xor rdi, rdi		; status = 0
	mov rax, 0x3c		; sys_exit
	syscall

fname:
	db "/etc/lsb-release", 0x00
