//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/69/problem69.hpp"

using problems::problem69;

TEST(Problem69, example) {
    auto res = problem69::solve(10);
    EXPECT_EQ(res, 6);
}

TEST(Problem69, solution) {
    auto res = problem69::solve();
    EXPECT_EQ(res, 510510);
}