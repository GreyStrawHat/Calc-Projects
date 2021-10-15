cmake_minimum_required(VERSION 3.16)
project(filecalc VERSION 0.0.0 LANGUAGES "C")

include_directories(${filecalc_SOURCE_DIR}/include)

find_program(CLANG_TIDY_PROG clang-tidy)
if(CLANG_TIDY_PROG)
        set(CMAKE_C_CLANG_TIDY ${CLANG_TIDY_PROG} "--checks=*,-llvm-include-order,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-*,-readability-magic-numbers,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling, -hiccp-no-assembler")
        set(CMAKE_C_FLAGS "-g -Werror")
    else()
        set(CMAKE_C_COMPILER gcc)
        set(CMAKE_C_FLAGS "-g -Wall -Werror -pedantic")
    endif()

if (DOCS EQUAL "1")
    message("Bulding docs for FileCalc")
    add_subdirectory(references)
else()
    message("Not bulding docs for FileCalc")
endif()

set(SOURCES
    src/main.c
)

add_executable(filecalc ${SOURCES})
target_link_libraries(filecalc calc pthread)
