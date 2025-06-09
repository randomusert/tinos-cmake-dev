# Collect all kernel sources
set(KERNEL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/boot.s
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/text.c
    PARENT_SCOPE
)

