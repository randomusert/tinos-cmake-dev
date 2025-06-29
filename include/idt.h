#ifndef IDT_H
#define IDT_H


#include "types.h"


// Interrupt Descriptor Table (IDT) structure and functions
// The IDT is used to define the interrupt handlers and their attributes in a system.
/*struct idt
{
    
    uint16_t offset_low;  // Offset bits 0-15
    uint16_t selector;    // Selector for the interrupt handler
    uint8_t zero;         // Reserved, must be zero
    uint8_t type_attr;    // Type and attributes
    uint16_t offset_high; // Offset bits 16-31
} __attribute__((packed));
*/

struct idt_entry {
    uint16_t offset_low;    // Lower 16 bits of the handler function address
    uint16_t selector;      // Kernel segment selector
    uint8_t zero;           // Reserved, set to zero
    uint8_t type_attr;      // Type and attributes
    uint16_t offset_high;   // Higher 16 bits of the handler function address
};


struct idt_ptr
{
    uint16_t limit; // Size of the IDT - 1
    uint32_t base;  // Address of the first entry in the IDT
} __attribute__((packed));
void idt_init(void);
void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t type_attr);


#endif // IDT_H
