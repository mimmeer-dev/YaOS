bits 16
org 0x7C00

jmp main
main:
    cli
    mov [bootdrv], dl
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x9000 ; safely above our code
    mov bp, 0x9000
    sti ; re-enable interrupts
    mov si, bootmsg
    call print
    mov ax, 0x0000
    mov es, ax
    mov bx, 0x1000
    mov dh, 0x01
    call disk_load
    jmp protmode


%include "src/disk.asm"

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

%include "src/gdt.asm"

protmode:
    mov al, 'P'
    mov ah, 0x0E
    int 0x10
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:initprot

bootmsg: db "YaOS: Yet another OS - Bootloader",0x00
bootdrv: db 0

[bits 32]

%include "src/khop.asm"

initprot:
    mov ax, DATA_SEG ; 5. update the segment registers
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ebp, 0x90000 ; 6. update the stack right at the top of the free space
    mov esp, ebp
    jmp hop

times 510-($-$$) db 0
dw 0xAA55