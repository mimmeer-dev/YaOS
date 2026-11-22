#include "video.h"
#include "io.h"

const char keycodes[128] = {
    0,   27,  '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', // 0x00 - 0x0E
    '\t','q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',      // 0x0F - 0x1C
    0,   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'','`',            // 0x1D - 0x29
    0,   '\\','z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,              // 0x2A - 0x36
    '*', 0,   ' ', 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,              // 0x37 - 0x43
    0,   0,   0,   '7', '8', '9', '-', '4', '5', '6', '+', '1', '2',            // 0x44 - 0x50
    '3', '0', '.', 0,   0,   0,   0,   0                                        // 0x51 - 0x58 (0x59-0x7F are 0)
};

char *welcome_msg = " /'\\  /''/  /'\n/_,/ /__/  _/ YaOS : Mimmeer 2026\n";
int bootdos() {
    clear(0x00);
    set_attrib(0x0B);
    kprint(welcome_msg);
    set_attrib(0x07);
    while (1) {
        kprint("\n> ");
        int prompting = 1;
        while (prompting) {
            if (inb(0x64) & 1) {
                uint8_t key = inb(0x60);
                if (key & 0x80) {
                    continue;
                }
                putchar(keycodes[key]);
            }
        }
        kprint("\nI ran it, 100% sure.");
    }
}