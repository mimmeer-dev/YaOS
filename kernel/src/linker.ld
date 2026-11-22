OUTPUT_FORMAT("binary")
ENTRY(_kentry)
SECTIONS {
    . = 0x1000;
    .text : { *(.text*) }
    .rodata : { *(.rodata*) }
    .data : { *(.data*) }
}