include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/include/
    ${LUA_INCLUDE_DIR}
    ${SFML_INCLUDE_DIR}
    )

set(SOURCES
    Widget.cpp
    )

add_library(
    gui
    Widget.cpp
    )

target_compile_definitions(
    gui PUBLIC
    -std=c++11
    -Wall
)

target_link_libraries(
    gui
    ${COMMON_LIBRARIES}
    )