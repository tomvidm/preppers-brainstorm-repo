add_subdirectory(common)
add_subdirectory(world)

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
    world
    )