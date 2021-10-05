cmake_minimum_required(VERSION 3.16)
project(threadcalc VERSION 0.0.0 LANGUAGES "C")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")

include_directories(${threadcalc_SOURCE_DIR}/hdrs)

find_program(CLANG_TIDY_PROG clang-tidy)
if(CLANG_TIDY_PROG)
        set(CMAKE_C_CLANG_TIDY ${CLANG_TIDY_PROG} "--checks=*,-android-cloexec-open,-llvmlibc-restrict-system-libc-headers,-llvm-include-order,-cppcoreguidelines-*,-readability-magic-numbers,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling, -hiccp-no-assembler")
        set(CMAKE_C_FLAGS "-g")
    else()
        set(CMAKE_C_COMPILER gcc)
        set(CMAKE_C_FLAGS "-g -Wall -pedantic")
    endif()

if (EXISTS ${DEBUG})
    if(${DEBUG} EQUAL 1)
        message("DEBUGGING VERSION")
        add_compile_definitions(DEBUG)
    else()
        message("RELEASE VERSION")
    endif()
endif()

FILE(GLOB CSources src/*.c)

add_executable(threadcalc ${CSources})

TARGET_LINK_LIBRARIES(threadcalc pthread)
