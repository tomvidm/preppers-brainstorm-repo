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
)

target_link_libraries(
    run-tests
    world
    gtest_main
    )