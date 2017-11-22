include_directories(
    ${LUA_INCLUDE_DIR}
    )

set(SOURCES
    DebugLine.cpp
    Logger.cpp
    ValueField.cpp
    DiscreteDistribution.cpp
    )

add_library(
    logger
    ${SOURCES}
    )