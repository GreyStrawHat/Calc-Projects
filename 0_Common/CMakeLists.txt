cmake_minimum_required (VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(SOURCE_FILES
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
set(HEADER_FILES
    "include/header-files/args.h"
    "include/header-files/calc.h"
    "include/header-files/error_msg.h"
    "include/header-files/handle_args.h"
    "include/header-files/signed_math_operations.h"
    "include/header-files/unsigned_math_operations.h"
    "include/header-files/signed_ec_operations.h"
    "include/header-files/unsigned_ec_operations.h"
    "include/header-files/default_case.h")

add_library(common_lib ${SOURCE_FILES} ${HEADER_FILES})

#project("SimpleCalc")

#add_executable(SimpleCalc)

#add_executable(SimpleCalc "SimpleCalc.c" "include/header-files/*" "src/source-files/*")

#nclude_directories("include/header-files" "src/source-files")

#target_sources(SimpleCalc PRIVATE ${SOURCE_FILES})