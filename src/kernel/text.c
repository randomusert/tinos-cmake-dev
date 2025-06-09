#include "text.h"

//defines for vga stuff
#define VGA_WIDTH 80
#define VGA_HEIGHT 60
#define VGA_MEMORY ((unsigned short*)0xb8000)
#define DEFAULT_COLOR 0x07

void text(const char *str) {
    int row = 0, col = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = str[i];

        if (ch == '\n') {
            row++;
            col = 0;
            continue;
        }

        if (row < VGA_HEIGHT && col < VGA_WIDTH) {
            unsigned short entry = ((unsigned short)DEFAULT_COLOR << 8) | (unsigned short)ch;
            VGA_MEMORY[row * VGA_WIDTH + col] = entry;
            col++;
        }

        if (col >= VGA_WIDTH) {
            col = 0;
            row++;
        }

        if (row >= VGA_HEIGHT)
            break;
    }
    
}