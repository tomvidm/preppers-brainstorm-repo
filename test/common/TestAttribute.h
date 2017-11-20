#ifndef TESTATTRIBUTE_H
#define TESTATTRIBUTE_H

#include "gtest/gtest.h"

#include "worldsim/AttributeContainer.h"
#include "worldsim/AttributeModifier.h"
#include "worldsim/Attribute.h"

namespace game {
    enum AttributeType
    {
        // Basic attributes
        SoftAttack,
        SoftDefense,
        HardAttack,
        HardDefense,
        Organization,
        Morale,
        Dicipline,
        Entrenchment,
        NUM_ATTRIBUTES
    };
    
    class TestAttribute : public testing::Test 
    {
    protected:
        virtual void SetUp();
    public:
        AttributeContainer<AttributeType> ustate;
        Attribute<float> attribute = Attribute<float>(1.f, 10.f);
        AttributeModifier<float> flatMod = AttributeModifier<float>(0.5f, ModifierOperation::Flat);
        AttributeModifier<float> multMod = AttributeModifier<float>(1.5f, ModifierOperation::Multiplicative);
    };
}

#endif