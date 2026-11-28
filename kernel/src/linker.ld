OUTPUT_FORMAT("binary")
ENTRY(loader)
SECTIONS {
    . = 0x1000;
    .text : {
        KEEP(*(.text.entry))
        *(.text*)
    }
    .rodata : { *(.rodata*) }
    .data : { *(.data*) }
}