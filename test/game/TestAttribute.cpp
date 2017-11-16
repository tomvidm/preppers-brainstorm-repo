#include "TestAttribute.h"

namespace game {
    void TestAttribute::SetUp()
    {
        ;
    }

    TEST_F(TestAttribute, AttributeModifierWorks)
    {
        EXPECT_EQ(flatMod.modify(1.5f), 2.f);
        EXPECT_EQ(multMod.modify(1.5f), 2.25f);
    }

    TEST_F(TestAttribute, AttributeWorks)
    {
        EXPECT_EQ(attribute.getBaseValue(), attribute.getValue()); // 1.f == 1.f
        attribute.addModifier(flatMod);                            // 1.f + 0.5f == 1.5f
        EXPECT_EQ(attribute.getValue(), 1.5f);                     
        attribute.addModifier(multMod);                            // (1.f + 0.5f) * 1.5f == 2.25f
        EXPECT_EQ(attribute.getValue(), 2.25f);                    
        attribute.setBaseValue(0.f);                               // (0.f + 0.5f) * 1.5f == 0.75f
        EXPECT_EQ(attribute.getValue(), 0.75f);                     
        attribute.addModifier(flatMod);                            // 1.f * 1.5f == 1.5f;
        EXPECT_EQ(attribute.getValue(), 1.5f);
    }
}