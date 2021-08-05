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

if (EXISTS ${DEBUG})
    if(${DEBUG} EQUAL 1)
        message("DEBUGGING VERSION")
        add_compile_definitions(DEBUG)
    else()
        message("RELEASE VERSION")
    endif()
endif()

add_library(the_maths SHARED ${filecalc_SOURCE_DIR}/src/the_maths.c)
add_executable(filecalc ${filecalc_SOURCE_DIR}/src/filecalc.c)
target_link_libraries(filecalc the_maths)

INSTALL(TARGETS the_maths DESTINATION ${filecalc_SOURCE_DIR}/bin)
INSTALL(TARGETS filecalc DESTINATION ${filecalc_SOURCE_DIR}/bin)