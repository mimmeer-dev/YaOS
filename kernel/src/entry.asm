bits 32
section .text.entry
global loader
extern _kentry

global loader

loader:
    call _kentry     ; Call your C kernel entry function
    cli
    hlt              ; Halt if _kentry ever returns