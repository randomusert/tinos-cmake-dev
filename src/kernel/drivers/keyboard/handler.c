#include "../../../../include/io.h"
#include "handler.h"

// Wait for a scancode to be available, read and convert it to ASCII
char read_char() {
    // Wait until output buffer is full (bit 0 of port 0x64)
    while ((inb(0x64) & 1) == 0) {
        // busy wait
    }

    unsigned char scancode = inb(0x60);

    static const char scancode_table[128] = {
        0,  27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
        '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
        'a','s','d','f','g','h','j','k','l',';','\'','`', 0, '\\',
        'z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' ',
        // Remaining entries zero by default
    };

    if (scancode > 127) return 0;  // Ignore out-of-bounds or break codes

    return scancode_table[scancode];
}
