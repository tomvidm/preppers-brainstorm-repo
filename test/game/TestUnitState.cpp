#include "TestUnitState.h"

namespace game {
    void TestUnitState::SetUp()
    {
        ;
    }

    TEST_F(TestUnitState, AttributeAssignment)
    {
        Attribute<float> attr = Attribute<float>(0.5f, 1.f);
        ustate.setAttribute(AttributeType::SoftAttack, attr);
        EXPECT_EQ(ustate.getAttributeValue(AttributeType::SoftAttack), 0.5f);
        AttributeModifier<float> mod = AttributeModifier<float>(0.75f, ModifierOperation::Flat);
        ustate.getAttribute(AttributeType::SoftAttack).addModifier(mod);
        EXPECT_EQ(ustate.getAttributeValue(AttributeType::SoftAttack), 1.f);
    }
}