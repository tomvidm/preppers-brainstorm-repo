include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    )

set(SOURCES
    Card.cpp
    Modifier.cpp
    UnitState.cpp
)

add_library(
    world
    ${SOURCES}
    )