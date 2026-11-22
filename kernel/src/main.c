#include "video.h"

void _kentry() {
    clear(0x0F);
    kprint("Hello, World! This is YaOS: ");
    set_attrib(0x3B);
    kprint("Yet Another Operating System\n");
    set_attrib(0x0F);
    kprint("The kernel is printing this text... ");
    set_attrib(0x5D);
    kprint("using 32-bit protected mode! :D\n");
    char *string = "Isn't this so cool?\n";
    set_attrib(0x4C);
    kprint(string);
    set_attrib(0x6E);
    kprint(string);
    set_attrib(0x2A);
    kprint(string);
    set_attrib(0x3B);
    kprint(string);
    set_attrib(0x19);
    kprint(string);
    set_attrib(0x5D);
    kprint(string);
    set_attrib(0x87);
    kprint("This text blinks.\n\n\n");
    set_attrib(0x0F);
    kprint("DEMO MENU\n");
    kprint("=========\n\n");
    set_attrib(0x07);
    kprint("1: Rainbow Demo\n");
    kprint("2: Recreation of BootDOS\n\n");
    set_attrib(0x0F);
    kprint("Press a key to select.\n\n");
    kprint("This project is open-source:\n");
    set_attrib(0x0B);
    kprint("https://github.com/mimmeer-dev/YaOS");
    return;
}