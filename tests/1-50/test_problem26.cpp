//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/26/problem26.hpp"

using problems::problem26;

TEST(Problem26, example) {
    auto res = problem26::solve(10);
    EXPECT_EQ(res, 7);
}

TEST(Problem26, solution) {
    auto res = problem26::solve();
    EXPECT_EQ(res, 983);
}