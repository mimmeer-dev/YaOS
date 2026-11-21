bits 16
org 0x7C00

jmp main
main:
    jmp $ ; hang to show we booted


times 510-($-$$) db 0
dw 0xAA55