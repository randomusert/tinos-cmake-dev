#include "poll_loop.h"
#include "../../../../include/text.h"

void keyboard_polling_loop() {
    while (1) {
        char c = read_char();
        if (c) {
            putchar(c);  // Implement your own print_char to output to screen
        }
    }
}
