BITS 64
global _start

_start:
	xor rax, rax
	inc rax
	xor rcx, rcx
	mov cl, 9
loop:
	add rax, rax
	dec rcx
	jns loop
end:
	jmp end
