#include "video.h"
#include <stdbool.h>

char* video_memory = (char*) 0xb8000;

int cursorX = 0;
int cursorY = 0;

void kputchr(int x, int y, char c, unsigned char attributes) {
    int memAddress = (x+(y*80))*2;
    *(video_memory+memAddress) = c;
    *(video_memory+memAddress+1) = attributes;
    return;
}

void putchar(char c, unsigned char attributes) {
    int memAddress = (cursorX+(cursorY*80))*2;
    *(video_memory+memAddress) = c;
    *(video_memory+memAddress+1) = attributes;
    cursorX++;
    if (cursorX>SCREEN_WIDTH-1) {
        cursorY++;
        cursorX = 0;
    }
    return;
}

void putstr(char *c, unsigned char attributes) {
    bool printing = true;
    int i = 0;
    while (printing) {
        char *letter = c+i;
        if (*letter==0x00) {
            printing=false;
            break;
        }
        putchar(*letter, attributes);
        i++;
    }
    return;
}