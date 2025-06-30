#include "../../../include/idt.h"

#define IDT_ENTRIES 256
struct idt_entry idt[IDT_ENTRIES];
struct idt_ptr idtp;

extern void idt_load(uint32_t);
extern void irq1_stub();



void idt_set_gate(int num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].offset_low = base & 0xFFFF;
    idt[num].selector = sel;
    idt[num].zero = 0;
    idt[num].type_attr = flags;
    idt[num].offset_high = (base >> 16) & 0xFFFF;
}

void idt_init() {
    idtp.limit = sizeof(idt) - 1;
    idtp.base = (uint32_t)&idt;

    idt_set_gate(0x21, (uint32_t)irq1_stub, 0x08, 0x8E); // IRQ1

    extern void irq0_stub(); // set up like irq1_stub

    idt_set_gate(0x20, (uint32_t)irq0_stub, 0x08, 0x8E);

    idt_load((uint32_t)&idtp);
}