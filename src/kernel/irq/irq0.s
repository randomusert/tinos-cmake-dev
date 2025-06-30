.globl irq0_stub
irq0_stub:
    pusha
    call irq0_handler
    popa
    iret
