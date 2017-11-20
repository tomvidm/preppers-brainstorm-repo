#include "gtest/gtest.h"

#include "common/AttributeIncludes.h"

namespace common {

    TEST(TestAttribute2, ModifiersWorks)
    {
        AttributeModifier<float> attrMod(0.5f, ModifierType::AddBaseMax);
        EXPECT_EQ(attrMod.getFactor(), 0.5f);
        EXPECT_EQ(attrMod.getModifierType(), ModifierType::AddBaseMax);
    }

    TEST(TestAttribute2, AttributeWorks)
    {
        Attribute<float> attr(5.f);
        EXPECT_EQ(attr.getValue(), 5.f);
        EXPECT_EQ(attr.getBaseMaxValue(), 5.f);
        EXPECT_EQ(attr.getMaxValue(), 5.f);

        AttributeModifier<float> mod1(1.f, ModifierType::AddMax);
        attr.addModifier(mod1);

        EXPECT_EQ(attr.getMaxValue(), 6.f);

        AttributeModifier<float> mod2(0.5f, ModifierType::MultiplyMax);
        attr.addModifier(mod2);

        EXPECT_EQ(attr.getMaxValue(), 3.f);
        EXPECT_EQ(attr.getBaseMaxValue(), 5.f);
        EXPECT_EQ(attr.getValue(), 3.f);

        AttributeModifier<float> mod3(-15.f, ModifierType::AddValue);
        attr.addModifier(mod3);

        EXPECT_EQ(attr.getValue(), 0.f);
        EXPECT_EQ(attr, 0.f);

        AttributeModifier<float> mod4(2.f, ModifierType::AddValue);
        attr.addModifier(mod4);

        EXPECT_EQ(attr.getValue(), 2.f);

        Attribute<float> attr2 = attr;

        EXPECT_EQ(attr.getValue(), attr2.getValue());
    }

    TEST(TestAttribute2, AttributeContainersWorks)
    {
        enum TestAttributes {
            Attr1,
            Attr2,
            Attr3,
            NUM_ATTRIBUTES
        };

        AttributeArray<float, TestAttributes> attrVec;
        attrVec.setAttribute(TestAttributes::Attr1, Attribute<float>(10.f));

        EXPECT_EQ(attrVec.getAttribute(TestAttributes::Attr1).getMaxValue(), 10.f);
    }
}