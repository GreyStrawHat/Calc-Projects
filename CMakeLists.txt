cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(
    JQRCalcProjects
    LANGUAGES "C"
    DESCRIPTION "JQR Example Projects v1.5"
)

project(
    SimpleCalc
    LANGUAGES "C"
)

include(jqr_main.cmake)

include_directories(0_Common/include/header-files)

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/0_Common/CMakeLists.txt")
    add_subdirectory(0_Common)
endif()

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/1_SimpleCalc/CMakeLists.txt")
    add_subdirectory(1_SimpleCalc)
endif()

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/2_FileCalc/CMakeLists.txt")
    add_subdirectory(2_FileCalc)
endif()

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/4_ThreadCalc/CMakeLists.txt")
    add_subdirectory(4_ThreadCalc)
endif()

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/5_NetCalc/CMakeLists.txt")
    add_subdirectory(5_NetCalc)
endif()

add_executable(SimpleCalc "1_SimpleCalc/src/source-files/simplecalc_main.c")

target_link_libraries(SimpleCalc common_lib simplecalc_lib)

set_target_properties(SimpleCalc PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/1_SimpleCalc/bin)

# EOF
