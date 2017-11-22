add_subdirectory(common)
add_subdirectory(worldsim)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/include/
    ${LUA_INCLUDE_DIR}
    )

add_executable(
    run
    main.cpp
    )

target_compile_definitions(
    run PUBLIC
    -std=c++11
    -Wall
)

target_link_libraries(
    run
    logger
    worldsim
    ${COMMON_LIBRARIES}
    )