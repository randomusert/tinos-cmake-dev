#include "../../../include/pic.h"

void pic_remap() {
    // Remap the PIC to avoid conflicts with the CPU' expection
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20); // Master offset to 0x20
    outb(0xA1, 0x28); // Slave offset to 0x28
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);

    outb(0x21, 0xFC); // Enable only IRQ1 (keyboard)
    outb(0xA1, 0xFF); // Disable all slave IRQs
}