cmake_minimum_required (VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

#project("fileCalc")

#add_executable(fileCalc)

#add_executable(fileCalc "fileCalc.c" "include/header-files/*" "src/source-files/*")

#include_directories("include/header-files" "src/source-files")

set(FILECALC_SOURCE_FILES
    "src/source-files/filecalc.c"
    "src/source-files/filecalc_main.c"
    "src/source-files/default_case64.c"
    "src/source-files/open_output_dir.c"
    "src/source-files/parse_solved_file.c"
    "src/source-files/parse_unsolved_file.c"
    "src/source-files/return_solved_struct.c"
    "src/source-files/return_unsolved_struct.c"
    "src/source-files/reverse_byte_string_order.c"
    "src/source-files/unsigned_ec_operations_64.c"
    "src/source-files/signed_ec_operations_64.c"
    "src/source-files/signed_math_operations_64.c"
    "src/source-files/unsigned_math_operations_64.c"
    "src/source-files/error_msg_64.c"
)

#target_sources(fileCalc PRIVATE ${SOURCE_FILES})

add_library(filecalc_lib ${FILECALC_SOURCE_FILES})

target_include_directories(filecalc_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/header-files)

#EOF