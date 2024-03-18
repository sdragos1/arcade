cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(arcade VERSION 0.1.0)

include_directories(common)

add_subdirectory(src/core)
