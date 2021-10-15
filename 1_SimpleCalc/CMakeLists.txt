cmake_minimum_required(VERSION 3.16)
project(simplecalc VERSION 0.0.0 LANGUAGES "C")

include_directories(${simplecalc_SOURCE_DIR}/include)

find_program(CLANG_TIDY_PROG clang-tidy)
if(CLANG_TIDY_PROG)
    set(CMAKE_C_CLANG_TIDY ${CLANG_TIDY_PROG}
        "--checks=*,-llvm-include-order,-cppcoreguidelines-*,-readability-magic-numbers,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-llvmlibc-restrict-system-libc-headers, -hiccp-no-assembler"
    )
    set(CMAKE_C_FLAGS "-g")
else()
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_C_FLAGS "-g -Wall -pedantic")
endif()

if (DOCS EQUAL "1")
    message("Bulding docs for SimpleCalc")
    add_subdirectory(references)
else()
    message("Not bulding docs for SimpleCalc")
endif()

project(
    SimpleCalc
    LANGUAGES "C"
    DESCRIPTION "Simple Calculator in C"
)

find_program(CLANG_TIDY_PROG clang-tidy)
if(CLANG_TIDY_PROG)
    set(CMAKE_C_CLANG_TIDY ${CLANG_TIDY_PROG}
        "--checks=*,-llvm-include-order,-cppcoreguidelines-*,-readability-magic-numbers,-readability-function-cognitive-complexity,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-llvmlibc-restrict-system-libc-headers, -hiccp-no-assembler"
        )
    set(CMAKE_C_FLAGS "-g -Werror")
else()
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_C_FLAGS "-g -Wall -Werror -pedantic")
endif()

set(TARGET simplecalc)

file(GLOB CSources src/*.c)

include_directories(include)

add_executable(simplecalc ${CSources})
target_link_libraries(simplecalc calc pthread)

