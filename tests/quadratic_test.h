#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "quadratic.h"
}

TEST(quadraticTest, twoRoots1)
{
    // Given
    double a = 1.0, b = -3.0, c = 2.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(2, res.rootsCount);
    EXPECT_EQ(1.0, res.x1);
    EXPECT_EQ(2.0, res.x2);
}

TEST(quadraticTest, twoRoots2)
{
    // Given
    double a = -4.0, b = 5.0, c = 6.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(2, res.rootsCount);
    EXPECT_EQ(-0.75, res.x1);
    EXPECT_EQ(2.0, res.x2);
}

TEST(quadraticTest, noRoots)
{
    // Given
    double a = 3.0, b = 11.0, c = 19.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(0, res.rootsCount);
}

TEST(quadraticTest, oneRoot)
{
    // Given
    double a = 9.0, b = 54.0, c = 81.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(1, res.rootsCount);
    EXPECT_EQ(-3.0, res.x1);
    EXPECT_EQ(-3.0, res.x2);
}
