cmake_minimum_required(VERSION 3.10)
project(arcade_tests)

file(GLOB_RECURSE TEST_SOURCES "*.cpp")

include_directories(/usr/local/include/criterion)

link_directories(/usr/local/lib)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME} criterion)

foreach(TEST_SOURCE IN LISTS TEST_SOURCES)
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_test(NAME ${TEST_NAME} COMMAND ${PROJECT_NAME} ${TEST_NAME})
endforeach()
