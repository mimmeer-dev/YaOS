#include "video.h"
#include "io.h"
#include <stdbool.h>
#include "rainbow_demo.h"
#include "bootdos.h"

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
    kprint("2: Recreation of BootDOS\n\n");
    set_attrib(0x0F);
    kprint("Press a key to select.\n\n");
    kprint("This project is open-source:\n");
    set_attrib(0x0B);
    kprint("https://github.com/mimmeer-dev/YaOS");
}

void _kentry() {
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
            else if (key==3)
            {
                bootdos();
                menu();
            }
            
        }
    }
    return;
}