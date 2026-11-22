#include "video.h"

void _kentry() {
    clear(0x07);
    kprint("Hello, World!\n");
    set_attrib(0x0B);
    kprint("The kernel is printing this text... ");
    set_attrib(0x0D);
    kprint("using 32-bit protected mode! :D\n");
    char *string = "Isn't this so cool?\n";
    set_attrib(0x0C);
    kprint(string);
    set_attrib(0x0E);
    kprint(string);
    set_attrib(0x0A);
    kprint(string);
    set_attrib(0x0B);
    kprint(string);
    set_attrib(0x09);
    kprint(string);
    set_attrib(0x0D);
    kprint(string);
    return;
}