cmake_minimum_required (VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

#project("fileCalc")

#add_executable(fileCalc)

#add_executable(fileCalc "fileCalc.c" "include/header-files/*" "src/source-files/*")

#include_directories("include/header-files" "src/source-files")

set(FILECALC_HEADER_FILES
    "include/header-files/filecalc_main.h"
    "include/header-files/filecalc.h"
    "include/header-files/parse_solved_file.h"
    "include/header-files/parse_unsolved_file.h"
    "include/header-files/return_solved_struct.h"
    "include/header-files/return_unsolved_struct.h"
    "include/header-files/reverse_byte_string_order.h"
)

set(FILECALC_SOURCE_FILES
    "src/source-files/filecalc_main.c"
    "src/source-files/filecalc.c"
    "src/source-files/parse_solved_file.c"
    "src/source-files/parse_unsolved_file.c"
    "src/source-files/return_solved_struct.c"
    "src/source-files/return_unsolved_struct.c"
    "src/source-files/reverse_byte_string_order.c"
)

#target_sources(fileCalc PRIVATE ${SOURCE_FILES})

add_library(filecalc_lib ${FILECALC_SOURCE_FILES} ${FILECALC_HEADER_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/header-files)

target_include_directories(filecalc_lib PRIVATE "include/header-files")

#EOF