#include "../../../include/pic.h"

void pic_remap() {
    // Remap the PIC to avoid conflicts with the CPU' expection
    outb(0x20, 0x11); // Start initialization sequence for master PIC
    outb(0xA0, 0x11); // Start initialization sequence for slave PIC

    outb(0x21, 0x20); // Set master PIC vector offset to 0x20
    outb(0xA1, 0x28); // Set slave PIC vector offset to 0x28

    outb(0x21, 0x04); // Tell master PIC that there is a slave PIC at IRQ2
    outb(0xA1, 0x02); // Tell slave PIC its cascade identity

    outb(0x21, 0x01); // Set master PIC to 8086/88 mode
    outb(0xA1, 0x01); // Set slave PIC to 8086/88 mode

    outb(0x21, 0x00); // Clear all masks on master PIC
    outb(0xA1, 0x00); // Clear all masks on slave PIC
}