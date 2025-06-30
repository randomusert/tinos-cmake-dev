add_library(irq
    irq1.s
    irq.c
    irq0.s
)
target_include_directories(irq PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})