add_library(console
    console.c
)

target_include_directories(console PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
