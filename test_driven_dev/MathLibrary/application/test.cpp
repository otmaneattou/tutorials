#include <gtest/gtest.h>
#include "MyMathLib.hpp"

TEST(TestSuiteSample, TestSample)
{
    int s = mySqrt(9);
    int r = mySqrt(4);
    ASSERT_EQ(3, s);
    ASSERT_EQ(2, r);
}

TEST(TestSuiteSample, TestSample2)
{
    int r = mySqrt(4);
    ASSERT_EQ(1, r);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
