#include "TestWorldsimParty.h"

namespace game {
    void TestWorldsimParty::SetUp()
    {
        wc1.setAttribute(WorldsimCharacter::Attributes::SoftAttack, 1.f);
        wc2.setAttribute(WorldsimCharacter::Attributes::SoftAttack, 5.f);
        wc3.setAttribute(WorldsimCharacter::Attributes::HardAttack, 10.f);
    }

    TEST_F(TestWorldsimParty, WorldsimParty)
    {
        AttributeModifier<float> mod = AttributeModifier<float>(2.f, ModifierOperation::Multiplicative);

        EXPECT_EQ(wp.getAttributeValue(WorldsimParty::Attributes::SoftAttack), 0.f);
        EXPECT_EQ(wp.getAttributeValue(WorldsimParty::Attributes::HardAttack), 0.f);

        wp.addCharacter(wc1);
        EXPECT_EQ(wp.getAttributeValue(WorldsimParty::Attributes::SoftAttack), 1.f);

        wp.addCharacter(wc2);
        EXPECT_EQ(wp.getAttributeValue(WorldsimParty::Attributes::SoftAttack), 6.f);

        wp.addCharacter(wc3);
        EXPECT_EQ(wp.getAttributeValue(WorldsimParty::Attributes::HardAttack), 10.f);
        EXPECT_EQ(wp.getAttributeValue(WorldsimParty::Attributes::SoftAttack), 6.f);

        wp.addAttributeModifierToCharacter("char1", WorldsimParty::Attributes::SoftAttack, mod);

        EXPECT_EQ(wp.getAttributeValue(WorldsimParty::Attributes::SoftAttack), 7.f);

        wp.addAttributeModifier(WorldsimParty::Attributes::SoftAttack, mod);

        EXPECT_EQ(wp.getAttributeValue(WorldsimParty::Attributes::SoftAttack), 14.f);
    }
}