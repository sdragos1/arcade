set(SRCS_CORE
    main.cpp)

add_executable(arcade ${SRCS_CORE})

set_target_properties(arcade PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
