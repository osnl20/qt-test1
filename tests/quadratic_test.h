#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "quadratic.h"
}

TEST(test1, quadratic)
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
