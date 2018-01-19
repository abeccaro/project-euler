//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/7/problem7.hpp"

using problems::problem7;

TEST(Problem7, example) {
    auto res = problem7::solve(6);
    EXPECT_EQ(res, 13);
}

TEST(Problem7, solution) {
    auto res = problem7::solve();
    EXPECT_EQ(res, 104743);
}