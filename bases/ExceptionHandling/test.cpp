#include <gtest/gtest.h>
#include "divide.cpp"

TEST(TestSuiteSample, TestSample)
{
    int a{100}, b{50};
    double *r{divide(a, b)};
    ASSERT_EQ(2, *r);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
