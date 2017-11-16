include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    )

set(SOURCES
    Card.cpp
    UnitState.cpp
)

add_library(
    worldsim
    ${SOURCES}
    )

target_link_libraries(
    worldsim
    logger
    )