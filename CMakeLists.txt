# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(tinoscmake C ASM)

set(CMAKE_C_FLAGS "-ffreestanding -O2 -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "-ffreestanding -nostdlib -lgcc -T ${CMAKE_SOURCE_DIR}/linker.ld")

# Set the include directory
include_directories(include)

# Add subdirectories
add_subdirectory(include)
add_subdirectory(src/console)
add_subdirectory(src/kernel)
add_subdirectory(src/kernel/drivers)
add_subdirectory(src/kernel/idt)
add_subdirectory(src/kernel/irq)

# Final kernel binary
add_executable(tinoscmake src/kernel/boot.s)

# Link object files
target_link_libraries(tinoscmake
    kernel
    console
    drivers
    include_libs
    idt
    irq
)


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