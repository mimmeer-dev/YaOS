#include "video.h"
#include "io.h"
#include <stdbool.h>
#include "rainbow_demo.h"

void menu() {
    clear(0x0F);
    kprint("Hello, World! This is YaOS: ");
    set_attrib(0x3B);
    kprint("Yet Another Operating System\n");
    set_attrib(0x0F);
    kprint("The kernel is printing this text... ");
    set_attrib(0x5D);
    kprint("using 32-bit protected mode! :D\n");
    set_attrib(0x0F);
    kprint("\n\nDEMO MENU\n");
    kprint("=========\n\n");
    set_attrib(0x07);
    kprint("1: Rainbow Demo\n");
    set_attrib(0x0F);
    //kprint("Press a key to select.\n\n");
    kprint("This project is open-source:\n");
    set_attrib(0x0B);
    kprint("https://github.com/mimmeer-dev/YaOS");
}

void PIC_init() {
    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);  // starts the initialization sequence (in cascade mode)
	wait_io();
	outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
	wait_io();
	outb(PIC1_DATA, 0x20);                 // ICW2: Master PIC vector offset
	wait_io();
	outb(PIC2_DATA, 0x28);                 // ICW2: Slave PIC vector offset
	wait_io();
	outb(PIC1_DATA, 1 << CASCADE_IRQ);        // ICW3: tell Master PIC that there is a slave PIC at IRQ2
	wait_io();
	outb(PIC2_DATA, CASCADE_IRQ);             // ICW3: tell Slave PIC its cascade identity
	wait_io();
	
	outb(PIC1_DATA, ICW4_8086);               // ICW4: have the PICs use 8086 mode (and not 8080 mode)
	wait_io();
	outb(PIC2_DATA, ICW4_8086);
	wait_io();

	// Unmask both PICs.
	outb(PIC1_DATA, 0);
	outb(PIC2_DATA, 0);
}

void _kentry() {
    //PIC_init();
    menu();
    while (true) {
        if (inb(0x64) & 1) {
            uint8_t key = inb(0x60);
            if (key & 0x80) {
                continue;
            }
            if (key==2) {
                rainbow();
                menu();
            }            
        }
    }
    return;
}