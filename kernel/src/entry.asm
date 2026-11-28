bits 32
global loader
extern _kentry

loader:
    call _kentry     ; Call your C kernel entry function
    cli
    hlt              ; Halt if _kentry ever returns