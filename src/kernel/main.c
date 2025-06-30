#include "../../include/text.h"
#include "../console/console.h"

#include "../../include/io.h"
#include "../../include/scancodes.h"

#include "../../include/idt.h"
#include "../../include/pic.h"
void kernel_main() {
    //init stuff. must be done before continuing!
    idt_init();       // Load the IDT with irq1_stub
    pic_remap();      // Remap the PIC (see below)

    asm volatile("sti"); // Enable CPU interrupts
    
    console();        // Start your shell
    while (1);
}
