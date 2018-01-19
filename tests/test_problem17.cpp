//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../src/problems/1-50/17/problem17.hpp"

using problems::problem17;

TEST(Problem17, example) {
    auto res = problem17::solve(5);
    EXPECT_EQ(res, 19);
}

TEST(Problem17, solution) {
    auto res = problem17::solve();
    EXPECT_EQ(res, 21124);
}