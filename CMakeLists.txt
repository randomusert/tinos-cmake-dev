cmake_minimum_required(VERSION 3.16)
project(TinOsCmake C ASM)

set(TARGET_TRIPLE i686-elf)

enable_language(ASM)

# the kernel's path relative from this root file
add_subdirectory(src/kernel)

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/linker.ld)

add_link_options(-T ${LINKER_SCRIPT})
add_executable(tinoscmake ${KERNEL_SOURCES})



# Copy kernel to isodir
add_custom_command(TARGET tinoscmake POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/isodir/boot/grub
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:tinoscmake> ${CMAKE_BINARY_DIR}/isodir/boot/myos
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/grub.cfg ${CMAKE_BINARY_DIR}/isodir/boot/grub/grub.cfg
)

# Create ISO image
add_custom_target(iso ALL
    COMMAND grub-mkrescue -o ${CMAKE_BINARY_DIR}/tinoscmake.iso ${CMAKE_BINARY_DIR}/isodir
    DEPENDS tinoscmake
)


set_target_properties(tinoscmake PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    LINKER_LANGUAGE C
)
