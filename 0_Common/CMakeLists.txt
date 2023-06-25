cmake_minimum_required (VERSION 3.25)

include_directories("include/header-files" "include/source-files")

project("SimpleCalc")

add_executable(SimpleCalc "SimpleCalc.c" "include/header-files" "src/source-files")
