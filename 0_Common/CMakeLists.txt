cmake_minimum_required(VERSION 3.16)


project(
    CalcCommon
    LANGUAGES "C"
    DESCRIPTION "Common calc libary"
)

find_program(CLANG_TIDY_PROG clang-tidy)
if(CLANG_TIDY_PROG)
    set(CMAKE_C_CLANG_TIDY ${CLANG_TIDY_PROG}
        "--checks=*,-llvm-include-order,-cppcoreguidelines-*,-altera-struct-pack-align,-android-cloexec-open,-hicpp-signed-bitwise,-readability-magic-numbers,-readability-function-cognitive-complexity,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-llvmlibc-restrict-system-libc-headers, -hiccp-no-assembler"
        )
    set(CMAKE_C_FLAGS "-g -Werror")
else()
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_C_FLAGS "-g -Wall -Werror -pedantic")
endif()

set(SOURCES
    src/calc_compute.c
    src/calc_io.c
    src/calc_tpool.c
    src/calc_pqueue.c
    src/calc_common.c
)

include_directories(include)

add_library(calc SHARED ${SOURCES})

add_library(calc-static STATIC ${SOURCES})
