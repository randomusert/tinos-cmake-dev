add_library(include_libs
    io.c
    scancodes.c
    text.c
    vga.c
)

target_include_directories(include_libs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
