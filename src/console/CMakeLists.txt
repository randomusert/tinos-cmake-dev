add_library(console
    console.c
    commands/ver.c
    commands/clear.c
)

target_include_directories(console PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
