#include "video.h"
#include "io.h"
#include <stdbool.h>
#include <stdint.h>

char* video_memory = (char*) 0xb8000;

int cursorX = 0;
int cursorY = 0;

unsigned char savedAttributes = 0x07;

void aputchar(int x, int y, char c, unsigned char attributes) {
    int memAddress = (x+(y*80))*2;
    *(video_memory+memAddress) = c;
    *(video_memory+memAddress+1) = attributes;
    return;
}

void kputchar(char c, unsigned char attributes) {
    int memAddress = (cursorX+(cursorY*80))*2;
    *(video_memory+memAddress) = c;
    *(video_memory+memAddress+1) = attributes;
    cursorX++;
    if (cursorX>VGA_SCREEN_WIDTH-1) {
        cursorY++;
        cursorX = 0;
    }
    return;
}

void cursor_pos(int x, int y) {
    short pos = y * VGA_SCREEN_WIDTH + x;

    // Send the low byte of the cursor position
    outb(VGA_CTRL_PORT, 0x0F);
    outb(VGA_DATA_PORT, (unsigned char)(pos & 0xFF));

    // Send the high byte of the cursor position
    outb(VGA_CTRL_PORT, 0x0E);
    outb(VGA_DATA_PORT, (unsigned char)((pos >> 8) & 0xFF));
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
        if (*letter=='\n') {
            cursorX=0;
            cursorY++;
            i++;
            continue;
        }
        kputchar(*letter, attributes);
        i++;
    }
    return;
}

void clear(unsigned char attributes) {
    savedAttributes = attributes;
    for (int i=0; i<(VGA_SCREEN_WIDTH*VGA_SCREEN_HEIGHT); i++) {
        int memAddress = i*2;
        *(video_memory+memAddress) = 0x00;
        *(video_memory+memAddress+1) = attributes;
    }
    cursorX = 0;
    cursorY = 0;
    cursor_pos(0,0);
    return;
}

void putchar(char c) {
    kputchar(c, savedAttributes);
    cursor_pos(cursorX,cursorY);
    return;
}

void kprint(char *c) {
    putstr(c, savedAttributes);
    cursor_pos(cursorX,cursorY);
    return;
}

void set_attrib(unsigned char attributes) {
    savedAttributes = attributes;
    return;
}