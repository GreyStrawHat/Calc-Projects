cmake_minimum_required(VERSION 3.16)
project(simplecalc VERSION 0.0.0 LANGUAGES "C")

include_directories(${simplecalc_SOURCE_DIR}/hdrs)

find_program(CLANG_TIDY_PROG clang-tidy)
if(CLANG_TIDY_PROG)
        set(CMAKE_C_CLANG_TIDY ${CLANG_TIDY_PROG} "--checks=*,-llvm-include-order,-cppcoreguidelines-*,-readability-magic-numbers,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-llvmlibc-restrict-system-libc-headers, -hiccp-no-assembler")
        set(CMAKE_C_FLAGS "-g")
    else()
        set(CMAKE_C_COMPILER gcc)
        set(CMAKE_C_FLAGS "-g -Wall -pedantic")
    endif()

cmake_minimum_required(VERSION 3.16)

project(
    SimpleCalc
    VERSION 0.1
    LANGUAGES C
    DESCRIPTION "Simple Calculator in C"
)

set(TARGET simplecalc)

FILE(GLOB CSources src/*.c)

include_directories(hdrs/)

add_executable(${TARGET} ${CSources})

