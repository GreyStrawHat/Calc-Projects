cmake_minimum_required (VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(SIMPLECALC_SOURCE_FILES
    src/source-files/args.c
    src/source-files/calc.c
    src/source-files/error_msg.c
    src/source-files/signed_math_operations.c
    src/source-files/unsigned_math_operations.c
    src/source-files/signed_ec_operations.c
    src/source-files/unsigned_ec_operations.c
    src/source-files/default_case.c
    src/source-files/handle_args.c
)

add_library(common_lib ${SIMPLECALC_SOURCE_FILES})

target_include_directories(common_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/header-files)