#ifndef TESTUNITSTATE_H
#define TESTUNITSTATE_H

#include "gtest/gtest.h"

#include "worldsim/Attribute.h"
#include "worldsim/UnitState.h"

namespace game {
    class TestUnitState : public testing::Test 
    {
    protected:
        virtual void SetUp();
    public:
        UnitState ustate;
    };
}

#endif