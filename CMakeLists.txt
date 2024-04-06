cmake_minimum_required(VERSION 3.20.0)

project(arcade VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/core)
add_subdirectory(src/graphicals)
add_subdirectory(src/games)

set(REPO_URL "https://github.com/G-Epitech/MAYBDF-ArcadeShared.git")

set(CLONE_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/../common")

execute_process(
    COMMAND git clone ${REPO_URL} ${CLONE_DESTINATION}
    RESULT_VARIABLE GIT_CLONE_RESULT
)

if(GIT_CLONE_RESULT EQUAL "0")
    message(STATUS "Clonage réussi!")
else()
    message(FATAL_ERROR "Échec du clonage!")
endif()

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()