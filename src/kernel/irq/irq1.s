.globl irq1_stub
.extern irq1_handler

irq1_stub:
    pusha                # Save registers
    call irq1_handler    # Call your C handler
    popa                 # Restore registers
    iret                 # Return from interrupt
