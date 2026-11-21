bits 16
org 0x7C00

jmp main
main:
    cli
    mov ss, ax
    mov sp, 0x9000 ; safely above our code 
    jmp $ ; hang to show we booted


bootmsg: db "YaOS: Yet another OS - Bootloader",0x0b,0x0a

times 510-($-$$) db 0
dw 0xAA55