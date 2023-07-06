cmake_minimum_required (VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(SOURCE_FILES
    src/source-files/SimpleCalc.c
    src/source-files/args.c
    src/source-files/calc.c
    src/source-files/error_msg.c
    src/source-files/math_operations.c
)

project("SimpleCalc")

add_executable(SimpleCalc)

#add_executable(SimpleCalc "SimpleCalc.c" "include/header-files/*" "src/source-files/*")

include_directories("include/header-files" "src/source-files")

target_sources(SimpleCalc PRIVATE ${SOURCE_FILES})