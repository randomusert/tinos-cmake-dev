#include "../../../include/pic.h"
#include "../../../include/io.h"
#include "../../../include/irq.h"
#include "../../../include/text.h"
#include "../../console/console.h"

/*
void irq1_handler() {
    uint8_t scancode = inb(0x60);
    char c = scancode_to_ascii(scancode);
    if (c) {
        kbd_buffer_push(c);
    }
    outb(0x20, 0x20); // Send End of Interrupt (EOI) signal to the PIC
}*/

void irq1_handler() {
    //print("irq1_handler called\n");
    //uint8_t scancode = inb(0x60);
    outb(0x20, 0x20); // Send End of Interrupt (EOI) signal to the PIC
}

void irq0_handler() {
    outb(0x20, 0x20); // EOI
}
