#ifndef TESTWORLDSIMCHARACTER_H
#define TESTWORLDSIMCHARACTER_H

#include "gtest/gtest.h"

#include "worldsim/WorldsimCharacter.h"

namespace game {
    class TestWorldsimCharacter : public testing::Test 
    {
    protected:
        virtual void SetUp();
    public:
        WorldsimCharacter wc;
        Attribute<float> attribute = Attribute<float>(1.f, 10.f);
    };
}

#endif