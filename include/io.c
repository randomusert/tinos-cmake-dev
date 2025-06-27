#include "io.h"
#include "scancodes.h"


unsigned char inb(unsigned short port) {
    unsigned char ret;
    __asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

void outb(unsigned short port, unsigned char val) {
    __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}




void scanf(char* buffer, size_t max_len) {
    size_t i = 0;
    while (i < max_len - 1) {
        uint8_t scancode = keyboard_read_scancode();
        
        // For simplicity: handle only letter keys, Enter, Backspace
        if (scancode == 0x1C) { // Enter key
            break;
        } else if (scancode == 0x0E && i > 0) { // Backspace
            i--;
            buffer[i] = '\0';
            // Optional: print backspace to console
        } else {
            // Map scancode to ASCII (very basic)
            char c = scancode_to_ascii(scancode); // Implement this
            if (c) {
                buffer[i++] = c;
                // Optional: echo character to screen
            }
        }
    }
    buffer[i] = '\0';
}
