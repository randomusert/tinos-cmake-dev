#include "scancodes.h"
#include "io.h"


#define KEYBOARD_PORT 0x60
#define STATUS_PORT   0x64

uint8_t keyboard_read_scancode() {
    while ((inb(STATUS_PORT) & 1) == 0); // Wait for key press
    return inb(KEYBOARD_PORT);
}

char scancode_to_ascii(unsigned char scancode) {
    static char scancode_table[] = {
        0, 27, '1', '2', '3', '4', '5', '6',
        '7', '8', '9', '0', '-', '=', '\b', /* Backspace */
        '\t', /* Tab */
        'q', 'w', 'e', 'r', /* 0x10 */
        't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0,
        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
        '\'', '`', 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n',
        'm', ',', '.', '/', 0, '*', 0, ' ', /* 0x39 = Space */
        // You can fill in more if needed
    };

    if (scancode > sizeof(scancode_table)) {
        return 0;
    }

    return scancode_table[scancode];
}