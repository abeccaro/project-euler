//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/80/problem80.hpp"

using problems::problem80;

TEST(Problem80, example) {
    auto res = problem80::solve(2);
    EXPECT_EQ(res, 475);
}

TEST(Problem80, solution) {
    auto res = problem80::solve();
    EXPECT_EQ(res, 40886);
}