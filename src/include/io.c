#include "io.h"
#include "scancodes.h"



static inline uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

static inline void outb(uint16_t port, uint8_t value) {
    __asm__ volatile("outb %0, %1" : : "a"(value), "Nd"(port));
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
