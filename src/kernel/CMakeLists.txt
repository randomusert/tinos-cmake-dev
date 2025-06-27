add_library(kernel
    main.c
)

target_include_directories(kernel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
