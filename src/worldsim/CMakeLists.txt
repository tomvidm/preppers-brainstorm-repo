include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    )

set(SOURCES
    WorldsimCharacter.cpp
    WorldsimParty.cpp
    Description.cpp
    DamageDescriptor.cpp
)

add_library(
    worldsim
    ${SOURCES}
    )

target_link_libraries(
    worldsim
    logger
    )