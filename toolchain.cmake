# toolchain configuration in cmake!
# DO NOT REMOVE!!!!!!!!
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR i686)

set(CMAKE_C_COMPILER i686-elf-gcc)
set(CMAKE_CXX_COMPILER i686-elf-g++)
set(CMAKE_ASM_COMPILER i686-elf-gcc)

set(CMAKE_C_FLAGS "-ffreestanding -nostdlib -nostdinc -fno-pic -m32 -Wall -Wextra")
set(CMAKE_ASM_FLAGS "-ffreestanding -m32")
set(CMAKE_EXE_LINKER_FLAGS "-ffreestanding -nostdlib")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)