#ifndef SCANCODES_H
#define SCANCODES_H

#include "types.h"

uint8_t keyboard_read_scancode();
char scancode_to_ascii(unsigned char scancode);

#endif