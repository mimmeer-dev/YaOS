#ifndef _YAOS_K_VIDEOH
#define _YAOS_K_VIDEOH

#define VGA_SCREEN_WIDTH 80
#define VGA_SCREEN_HEIGHT 25

#define VGA_CTRL_PORT 0x3D4
#define VGA_DATA_PORT 0x3D5

void cursor_pos(int x, int y);

void putchar(char c);

void clear(unsigned char attributes);

void kprint(char *c);

void aputchar(int x, int y, char c, unsigned char attributes);

void set_attrib(unsigned char attributes);

#endif