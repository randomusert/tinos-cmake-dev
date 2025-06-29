add_library(idt
    idt.c
    idt_load.s
    pic.c
)

target_include_directories(idt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})