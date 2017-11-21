include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${gtest_SOURCE_DIR}/include
)

add_executable(
    run-tests
    common/TestInterval.cpp
    common/TestLimitedValue.cpp
    common/TestDiscreteDistribution.cpp
    common/TestAttribute.cpp
    common/TestAttribute2.cpp
    common/TestObjectPool.cpp
    game/TestActor.cpp
    game/TestWorldsimCharacter.cpp
    game/TestWorldsimParty.cpp
    game/TestDamageable.cpp
    game/TestBody.cpp
    game/TestPerson.cpp
)

target_link_libraries(
    run-tests
    worldsim
    logger
    gtest_main
    )