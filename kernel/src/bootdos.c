#include "video.h"

char *welcome_msg = " /'\\  /''/  /'\n/_,/ /__/  _/ YaOS : Mimmeer 2026\n";
int bootdos() {
    clear(0x00);
    set_attrib(0x0B);
    kprint(welcome_msg);
    set_attrib(0x07);
    while (1) {
        kprint("> ");
        int prompting = 1;
        while (prompting) {

        }
    }
}