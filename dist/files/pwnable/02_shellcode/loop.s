BITS 64
global _start

_start:
	mov rax, 1
	mov rcx, 10
loop:
	add rax, rax
	dec rcx
	jnz loop
end:
	jmp end
