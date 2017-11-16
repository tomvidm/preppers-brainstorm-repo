#include "TestAttribute.h"

namespace game {
    void TestAttribute::SetUp()
    {
        ;
    }

    TEST_F(TestAttribute, AttributeModifier)
    {
        EXPECT_EQ(flatMod.modify(1.5f), 2.f);
        EXPECT_EQ(multMod.modify(1.5f), 2.25f);
    }

    TEST_F(TestAttribute, Attribute)
    {
        // Without modification, base value and modified values are equal
        EXPECT_EQ(attribute.getBaseValue(), attribute.getValue());
        attribute.addModifier(flatMod); 
        // 1.f + 0.5f == 1.5f
        EXPECT_EQ(attribute.getValue(), 1.5f);                     
        attribute.addModifier(multMod);                           
        // (1.f + 0.5f) * 1.5f == 2.25f
        EXPECT_EQ(attribute.getValue(), 2.25f);                    
        attribute.setBaseValue(0.f);   
        // (0.f + 0.5f) * 1.5f == 0.75f                           
        EXPECT_EQ(attribute.getValue(), 0.75f);                     
        attribute.addModifier(flatMod);
        // (0.f + 0.5f + 0.5f) * 1.5f == 1.5f
        EXPECT_EQ(attribute.getValue(), 1.5f);
        // If successful, flat and multiplicative modifiers
        // are correctly sorted so that flat modifiers are
        // applied before multiplicative ones.

        // Default turn lifetime of attribute modifiers are 1 turn.
        // Calling onTurn makes the modifiers die.
        attribute.onTurn();
        EXPECT_EQ(attribute.getValue(), 0.f);
    }

    TEST_F(TestAttribute, AttributeContainer)
    {
        Attribute<float> attr = Attribute<float>(0.5f, 1.f);
        ustate.setAttribute(AttributeType::SoftAttack, attr);
        EXPECT_EQ(ustate.getAttributeValue(AttributeType::SoftAttack), 0.5f);
        AttributeModifier<float> mod = AttributeModifier<float>(0.75f, ModifierOperation::Flat);
        ustate.getAttribute(AttributeType::SoftAttack).addModifier(mod);
        EXPECT_EQ(ustate.getAttributeValue(AttributeType::SoftAttack), 1.f);
        // Test modifier lifetime.
        ustate.onTurn();
        EXPECT_EQ(ustate.getAttributeValue(AttributeType::SoftAttack), 0.5f);
    }
}