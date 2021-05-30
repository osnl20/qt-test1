#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "quadratic.h"
}

TEST(quadratic_test, no_roots)
{
    // Given
    double a = 3.0, b = 11.0, c = 19.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(NO_ROOTS, res.solution_type);
}

TEST(quadratic_test, one_root)
{
    // Given
    double a = 9.0, b = 54.0, c = 81.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(ONE_ROOT, res.solution_type);
    EXPECT_EQ(-3.0, res.x1);
}

TEST(quadratic_test, two_roots_1)
{
    // Given
    double a = 1.0, b = -3.0, c = 2.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(TWO_ROOTS, res.solution_type);
    EXPECT_EQ(1.0, res.x1);
    EXPECT_EQ(2.0, res.x2);
}

TEST(quadratic_test, two_roots_2)
{
    // Given
    double a = -4.0, b = 5.0, c = 6.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(TWO_ROOTS, res.solution_type);
    EXPECT_EQ(-0.75, res.x1);
    EXPECT_EQ(2.0, res.x2);
}

TEST(quadratic_test, stranger_things_1) {
    // Given
    double a = 1.0, b = 0.0, c = 0.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(ONE_ROOT, res.solution_type);
    EXPECT_EQ(0.0, res.x1);
}

TEST(quadratic_test, stranger_things_2) {
    // Given
    double a = 0.0, b = 1.0, c = 0.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(ONE_ROOT, res.solution_type);
    EXPECT_EQ(0.0, res.x1);
}

TEST(quadratic_test, stranger_things_3) {
    // Given
    double a = 0.0, b = 0.0, c = 1.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(NO_ROOTS, res.solution_type);
}

TEST(quadratic_test, stranger_things_4) {
    // Given
    double a = 0.0, b = 0.0, c = 0.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(ANY_VALUE, res.solution_type);
}

TEST(quadratic_test, overflow_case_1) {
    // Given
    double a = DBL_MAX, b = DBL_MAX, c = DBL_MAX;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(CALCULATION_OVERFLOW, res.solution_type);
}

TEST(quadratic_test, overflow_case_2) {
    // Given
    double a = 0.0, b = 0.1, c = DBL_MAX;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(CALCULATION_OVERFLOW, res.solution_type);
}

TEST(print_and_solve_equationc_test, just_test) {
    // Given
    double a = -2.0, b = 3.0, c = 5.0;

    // When
    Roots res = quadratic(a, b, c);

    // Then
    EXPECT_EQ(TWO_ROOTS, res.solution_type);
    EXPECT_EQ(-1.0, res.x1);
    EXPECT_EQ(2.5, res.x2);
}
