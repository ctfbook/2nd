extern puts
extern exit

global _start
section .text

_start:
  call obfuscated
  xor edi, edi
  call exit

obfuscated:
  push rbp
  mov rbp, rsp
  ; blahblah
  db 0x48, 0xB8
.@Label:
  db 0xE8, 0x09, 0x00, 0x00, 0x00, 0xC9, 0xC3, 0x90
  xor edx, edx
  jz .@Label
  leave
  ret

evil:
  mov rdi, evilMessage
  call puts
  ret

section .data
evilMessage: db "Evil function!", 0x00
