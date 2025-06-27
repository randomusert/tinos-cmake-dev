//copyright (C) 2025-present Randomusert. licensed under a custom license named RST license
// see LICENSE file for more details

#include "../../../../include/io.h"
#include "handler.h"

char read_char() {
    static const char scancode_table[128] = {
        0,  27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
        '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
        'a','s','d','f','g','h','j','k','l',';','\'','`', 0, '\\',
        'z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' ',
        // Fill rest with 0s
    };

    while ((inb(0x64) & 1) == 0); // wait for key press
    uint8_t sc = inb(0x60);

    if (sc & 0x80) return 0;  // ignore key release
    return sc < 128 ? scancode_table[sc] : 0;
}
