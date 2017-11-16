#ifndef TESTWORLDSIMCHARACTER_H
#define TESTWORLDSIMCHARACTER_H

#include "gtest/gtest.h"

#include "worldsim/WorldsimParty.h"
#include "worldsim/WorldsimCharacter.h"
#include "worldsim/AttributeModifier.h"

namespace game {
    class TestWorldsimParty : public testing::Test 
    {
    protected:
        virtual void SetUp();
        
        WorldsimCharacter wc1 = WorldsimCharacter("char1");
        WorldsimCharacter wc2 = WorldsimCharacter("char2");
        WorldsimCharacter wc3 = WorldsimCharacter("char3");

        WorldsimParty wp;

        Attribute<float> attribute = Attribute<float>(1.f, 10.f);
    };
}

#endif