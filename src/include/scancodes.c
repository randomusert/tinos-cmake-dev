#include "scancodes.h"
#include "io.h"


#define KEYBOARD_PORT 0x60
#define STATUS_PORT   0x64

static uint8_t keyboard_read_scancode() {
    while ((inb(STATUS_PORT) & 1) == 0); // Wait for key press
    return inb(KEYBOARD_PORT);
}