function(create_graphic_library TARGET_NAME DEPENDENCY)
    file(GLOB_RECURSE LIB_SOURCES "${TARGET_NAME}/*.cpp")

    set(LIB_NAME arcade_${TARGET_NAME})

    add_library(${LIB_NAME} SHARED ${LIB_SOURCES})

    target_include_directories(${LIB_NAME} PUBLIC ${TARGET_NAME} ${PROJECT_SOURCE_DIR}/common ${PROJECT_SOURCE_DIR}/shared)

    set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")

    target_link_libraries(${LIB_NAME} ${DEPENDENCY})

    set_target_properties(${LIB_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
endfunction()

## Add the graphical libraries here "create_graphic_library(<library_name>)"
set(SFML_DEPENDENCY sfml-graphics sfml-system sfml-window sfml-audio)
set(SDL2_DEPENDENCY SDL2 SDL2_image SDL2_ttf SDL2_mixer)

create_graphic_library(ncurses ncurses)
create_graphic_library(sfml "${SFML_DEPENDENCY}")
create_graphic_library(sdl2 "${SDL2_DEPENDENCY}")