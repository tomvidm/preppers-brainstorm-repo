#include "TestWorldsimCharacter.h"

namespace game {
    void TestWorldsimCharacter::SetUp()
    {
        ;
    }

    TEST_F(TestWorldsimCharacter, AttributeAssignment)
    {
        wc.setAttribute(WorldsimCharacter::Attributes::SoftAttack, attribute);
        EXPECT_EQ(wc.getAttribute(WorldsimCharacter::Attributes::SoftAttack), 1.f);
        AttributeModifier<float> mod = AttributeModifier<float>(2.f, ModifierOperation::Multiplicative);
        wc.addAttributeModifier(WorldsimCharacter::Attributes::SoftAttack, mod);
        EXPECT_EQ(wc.getAttribute(WorldsimCharacter::Attributes::SoftAttack), 2.f);
    }
}