#include "gtest/gtest.h"

#include "common/LimitedValue.h"

TEST(TestLimitedValue, LimitedValueWorksAsIntended)
{
    common::LimitedValue<float> limval = common::LimitedValue<float>(0.5f, 0.f, 1.f);
    EXPECT_EQ(limval.getMax(), 1.f);
    EXPECT_EQ(limval.getMin(), 0.f);
    EXPECT_EQ(limval.getValue(), 0.5f);
    limval += 0.1f;
    EXPECT_EQ(limval.getValue(), 0.6f);
    limval += 1.f;
    EXPECT_EQ(limval.getValue(), 1.f);
    limval -= 10.f;
    EXPECT_EQ(limval.getValue(), 0.f);
    EXPECT_TRUE(limval == 0.f);


}
