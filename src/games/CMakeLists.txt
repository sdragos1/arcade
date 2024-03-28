function(create_game TARGET_NAME)
    include_directories(${PROJECT_SOURCE_DIR}/common)

    file(GLOB_RECURSE GAME_SOURCES "*.cpp" ${PROJECT_SOURCE_DIR}/common/*.cpp)

    add_library(${TARGET_NAME} SHARED ${GAME_SOURCES})

    target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/common)

    target_link_libraries(${TARGET_NAME} uuid)

    set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "arcade_")

    set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
endfunction()

## Create the games here "create_game(<game_name>)"
create_game(test)
