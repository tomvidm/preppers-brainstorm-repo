include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/include/
    ${LUA_INCLUDE_DIR}
    ${SFML_INCLUDE_DIR}
    )

set(SOURCES
    Window.cpp
    )

add_library(
    engine
    Window.cpp
    )

target_compile_definitions(
    engine PUBLIC
    -std=c++11
    -Wall
)

target_link_libraries(
    engine
    ${COMMON_LIBRARIES}
    )