include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    )

set(SOURCES
    WorldsimCharacter.cpp
    WorldsimParty.cpp
    Actor.cpp
    Body.cpp
    BodyPart.cpp
    Description.cpp
    DamageDescriptor.cpp
    Damageable.cpp
    Person.cpp
    Trait.cpp
)

add_library(
    worldsim
    ${SOURCES}
    )

target_link_libraries(
    worldsim
    logger
    )