#include <vector>

#include "gtest/gtest.h"

#include "common/DiscreteDistribution.h"

TEST(TestDiscreteDistribution, WorkisAsIntended)
{
    std::vector<int> w1 = { 4, 3, 2, 1 };
    std::vector<int> w2 = { 1, 2, 3, 4 };
    int hist1[4];
    int hist2[4];
    int hist3[4];

    common::DiscreteDistribution pdf;
    pdf.setWeights(w1);

    for (int i = 0; i < 1000; i++)
    {
        hist1[pdf.rand()]++;
    }

    for (int i = 0; i < 1000; i++)
    {
        hist2[pdf.rand(w2)]++;
    }

    for (int i = 0; i < 1000; i++)
    {
        hist3[pdf.rand()]++;
    }

    EXPECT_TRUE(hist1[0] > hist1[1]);
    EXPECT_TRUE(hist1[1] > hist1[2]);
    EXPECT_TRUE(hist1[2] > hist1[3]);
    EXPECT_TRUE(hist2[0] < hist2[1]);
    EXPECT_TRUE(hist2[1] < hist2[2]);
    EXPECT_TRUE(hist2[2] < hist2[3]);
    EXPECT_TRUE(hist3[0] > hist3[1]);
    EXPECT_TRUE(hist3[1] > hist3[2]);
    EXPECT_TRUE(hist3[2] > hist3[3]);


}