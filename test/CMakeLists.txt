include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${gtest_SOURCE_DIR}/include
)

add_executable(
    run-tests
    trivialTest.cpp
    common/TestInterval.cpp
    common/TestLimitedValue.cpp
    game/TestUnitState.cpp
    game/TestAttribute.cpp
)

target_link_libraries(
    run-tests
    worldsim
    logger
    gtest_main
    )