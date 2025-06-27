#include "text.h"
#include "types.h"
#include "vga.h"

//defines for vga stuff
//also defines variables
#define VGA_WIDTH 80
#define VGA_HEIGHT 60
#define VGA_MEMORY ((unsigned short*)0xb8000)
#define DEFAULT_COLOR 0x07
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;

int cursor_x = 0;
int cursor_y = 0;


void putchar(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
        return;
    }

    vga_buffer[cursor_y * VGA_WIDTH + cursor_x] = vga_entry(c, 0x07);
    cursor_x++;

    if (cursor_x >= VGA_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }

    if (cursor_y >= VGA_HEIGHT) {
        scroll_screen();
        cursor_y = VGA_HEIGHT - 1;
    }
}

void scroll_screen() {
    for (int y = 1; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[(y - 1) * VGA_WIDTH + x] = vga_buffer[y * VGA_WIDTH + x];
        }
    }

    // Clear last line
    for (int x = 0; x < VGA_WIDTH; x++) {
        vga_buffer[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = vga_entry(' ', 0x07);
    }
}

void print(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
    }
}
