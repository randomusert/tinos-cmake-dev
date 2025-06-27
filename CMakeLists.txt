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

# Final kernel binary
add_executable(tinoscmake src/kernel/boot.s)

# Link object files
target_link_libraries(tinoscmake
    kernel
    console
    drivers
    include_libs
)