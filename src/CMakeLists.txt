add_subdirectory(common)
add_subdirectory(worldsim)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    )

add_executable(
    run
    main.cpp
    )

target_link_libraries(
    run
    logger
    worldsim
    )