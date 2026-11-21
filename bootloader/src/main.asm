bits 16
org 0x7C00

jmp main
main:
    xor ax, ax
    mov ds, ax
    mov es, ax
    cli
    mov ss, ax
    mov sp, 0x9000 ; safely above our code
    mov bp, 0x9000
    sti ; re-enable interrupts
    mov si, bootmsg
    call print
    jmp $ ; hang to show we booted

; PRINT
; DS:SI : String Address
print:
    pusha
    mov ah,0x0e
    jmp .loop

.loop:
    lodsb
    cmp al,0x00
    je .end
    int 0x10
    jmp .loop

.end:
    popa
    ret

bootmsg: db "YaOS: Yet another OS - Bootloader",0x00

times 510-($-$$) db 0
dw 0xAA55