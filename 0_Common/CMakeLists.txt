cmake_minimum_required (VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(SOURCE_FILES
    src/source-files/args.c
    src/source-files/calc.c
    src/source-files/error_msg.c
    src/source-files/math_operations.c
    src/source-files/default_case.c
)
set(HEADER_FILES
    "include/header-files/args.h"
    "include/header-files/calc.h"
    "include/header-files/error_msg.h"
    "include/header-files/math_operations.h"
    "include/header-files/magic_num.h"
    "include/header-files/default_case.h")

add_library(lib1 ${SOURCE_FILES} ${HEADER_FILES})

#project("SimpleCalc")

#add_executable(SimpleCalc)

#add_executable(SimpleCalc "SimpleCalc.c" "include/header-files/*" "src/source-files/*")

#nclude_directories("include/header-files" "src/source-files")

#target_sources(SimpleCalc PRIVATE ${SOURCE_FILES})