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
        EXPECT_EQ(attribute.getBaseValue(), attribute.getValue());
        attribute.addModifier(flatMod);
        EXPECT_EQ(attribute.getValue(), 1.5f);
        attribute.addModifier(multMod);
        EXPECT_EQ(attribute.getValue(), 2.25f);
    }
}