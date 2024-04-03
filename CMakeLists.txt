cmake_minimum_required(VERSION 3.20.0)

project(arcade VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

execute_process(
    COMMAND git submodule init
    COMMAND git submodule update --remote --merge
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE submodule_result
)
if(NOT ${submodule_result} EQUAL 0)
    message(FATAL_ERROR "Failed to update submodules")
endif()

add_subdirectory(src/core)
add_subdirectory(src/graphicals)
add_subdirectory(src/games)

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()