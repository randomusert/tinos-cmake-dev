add_library(drivers
    keyboard/handler.c
    keyboard/poll_loop.c
)

target_include_directories(drivers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})