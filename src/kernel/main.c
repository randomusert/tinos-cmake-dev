#include "../../include/text.h"
#include "../console/console.h"

#include "../../include/io.h"
#include "../../include/scancodes.h"

#include "../../include/idt.h"
#include "../../include/pic.h"
void kernel_main() {
    //init stuff. must be done before continuing!
    idt_init(); // Initialize the Interrupt Descriptor Table
    pic_remap(); // Remap the Programmable Interrupt Controller (PIC)
    
    //text("welcome to tinos cmake edition\nthis os is for the fun and is not really a prod os\nNOTE: this is a hobby os and not a commercial os");
    console();
    char input_buffer[128];
    int input_pos = 0;

    asm volatile("sti"); // Enable interrupts globally

    while (1) {
        char c = read_char();  // Blocking keyboard input
        if (c == '\b') {
            if (input_pos > 0) {
                input_pos--;
                putchar('\b');  // Erase char on screen
            }
        } else if (c == '\n' || c == '\r') {
            print("\n");
            input_buffer[input_pos] = '\0';
            // Handle input buffer, e.g. check commands here
            print("> ");
            input_pos = 0;
        } else if (input_pos < sizeof(input_buffer) - 1) {
            input_buffer[input_pos++] = c;
            putchar(c);
        }
       /*
       unsigned char data = inb(0x60); //TEST!
       putchar('[');
       print(data);
       putchar(']');
       for (volatile int i = 0; i < 100000; i++); // Simple delay to avoid flooding the console. socalled crude delay
       */
      

    }
}
