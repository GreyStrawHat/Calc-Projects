cmake_minimum_required (VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

#project("SimpleCalc")

#add_executable(SimpleCalc)

#add_executable(SimpleCalc "SimpleCalc.c" "include/header-files/*" "src/source-files/*")

include_directories("include/header-files" "src/source-files")

#target_sources(SimpleCalc PRIVATE ${SOURCE_FILES})

add_library(simplecalc_lib "src/source-files/simplecalc_main.c" "include/header-files/simplecalc_main.h")

#EOF