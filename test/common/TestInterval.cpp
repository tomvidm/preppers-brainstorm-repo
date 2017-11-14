#include "gtest/gtest.h"

#include "common/Interval.h"

TEST(TestInterval, IntervalWorksAsIntended)
{
    common::Interval<float> interval(0.f, 1.f);
    EXPECT_FALSE(interval.contains(-1.f));
    EXPECT_TRUE(interval.contains(0.2f));
    EXPECT_FALSE(interval.contains(1.02f));
}
