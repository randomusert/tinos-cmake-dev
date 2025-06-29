#include "../../../include/pic.h"
#include "../../../include/io.h"
#include "../../../include/irq.h"
#include "../../../include/text.h"


void irq1_handler() {
    uint8_t scancode = inb(0x60);
    print(scancode);
    print("");
    outb(0x20, 0x20); // Send End of Interrupt (EOI) signal to the PIC
}