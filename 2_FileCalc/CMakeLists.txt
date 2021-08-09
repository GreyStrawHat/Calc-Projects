cmake_minimum_required(VERSION 3.16)
project(filecalc VERSION 0.0.0 LANGUAGES "C")

include_directories(${filecalc_SOURCE_DIR}/hdrs)

find_program(CLANG_TIDY_PROG clang-tidy)
if(CLANG_TIDY_PROG)
        set(CMAKE_C_CLANG_TIDY ${CLANG_TIDY_PROG} "--checks=*,-llvm-include-order,-cppcoreguidelines-*,-readability-magic-numbers,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling, -hiccp-no-assembler")
        set(CMAKE_C_FLAGS "-g")
    else()
        set(CMAKE_C_COMPILER gcc)
        set(CMAKE_C_FLAGS "-g -Wall -pedantic")
    endif()

add_executable(filecalc ${filecalc_SOURCE_DIR}/src/filecalc.c)

#add and link libraries as needed, install to ${filecalc_SOURCE_DIR}/build

INSTALL(TARGETS filecalc DESTINATION ${filecalc_SOURCE_DIR}/build)