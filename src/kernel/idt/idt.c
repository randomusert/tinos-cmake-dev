#include "../../../include/idt.h"

#define IDT_ENTRIES 256
struct idt_entry idt[IDT_ENTRIES];
struct idt_ptr idtp;

extern void idt_load(uint32_t);

void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t type_attr) {
    idt[num].offset_low = base & 0xFFFF;
    idt[num].selector = selector;
    idt[num].zero = 0;
    idt[num].type_attr = type_attr;
    idt[num].offset_high = (base >> 16) & 0xFFFF;
}

void idt_init(void) {
    idtp.limit = (sizeof(struct idt_entry) * IDT_ENTRIES) - 1;
    idtp.base = (uint32_t)&idt;

    for (int i = 0; i < IDT_ENTRIES; i++) {
        idt_set_gate(i, 0, 0x08, 0x8E);
    }

    extern void irq1_stub();
    idt_set_gate(0x21, (uint32_t)irq1_stub, 0x08, 0x8E); // Example for IRQ1

    idt_load((uint32_t)&idtp);
    
}