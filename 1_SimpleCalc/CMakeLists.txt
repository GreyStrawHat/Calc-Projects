cmake_minimum_required (VERSION 3.16)

include_directories("include/header-files" "src/source-files")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

project("SimpleCalc")

add_executable(SimpleCalc "src/source-files/SimpleCalc.c" "src/source-files/args.c" "src/source-files/calc.c" "src/source-files/error_msg.c" "src/source-files/math_operations.c")

#add_executable(SimpleCalc "SimpleCalc.c" "include/header-files/*" "src/source-files/*")
