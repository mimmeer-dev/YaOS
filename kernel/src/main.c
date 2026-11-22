#include "video.h"

void _kentry() {
    for (int i=0; i<7; i++) {
        putstr("Hello, World! ", 0x07);
    }
    return;
}