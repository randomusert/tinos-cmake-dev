add_library(drivers
    keyboard/handler.c
)

target_include_directories(drivers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})