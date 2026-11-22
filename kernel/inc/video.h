#ifndef _YAOS_K_VIDEOH
#define _YAOS_K_VIDEOH

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

void kputchr(int x, int y, char c, unsigned char attributes);

void putchar(char c, unsigned char attributes);

void putstr(char *c, unsigned char attributes);

void clear(unsigned char attributes);

#endif