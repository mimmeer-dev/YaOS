#include "video.h"
#include "io.h"

void rainbow() {
    clear(0x00);
    char *string = "Rainbow colours!!! :D :D\n";
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
    kprint("Press SPACE to return.");
    while (1) {
        uint8_t key = inb(0x60);
        if (key!=0) {
            if (key==0x39) {
                PIC_sendEOI(0x20);
                break;
            }
        }
    }
    return;
}