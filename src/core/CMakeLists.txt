include_directories(${PROJECT_SOURCE_DIR}/common)

set(SRCS_CORE
    Main.cpp
    Core.cpp
    Menu.cpp
    HighScore.cpp
    library/GraphicList.cpp
    library/GameList.cpp
    library/loader/Directory.cpp
    utils/CoreUtils.cpp)

add_executable(arcade ${SRCS_CORE})

target_compile_options(arcade PRIVATE -fno-gnu-unique)

target_include_directories(arcade PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/common ${PROJECT_SOURCE_DIR}/shared)

target_link_libraries(arcade ${CMAKE_DL_LIBS})

set_target_properties(arcade PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
