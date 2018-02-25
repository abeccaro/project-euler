//
// Created by Alex Beccaro on 25/02/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/86/problem86.hpp"

using problems::problem86;

TEST(Problem86, example) {
    auto res = problem86::solve(2000);
    EXPECT_EQ(res, 100);
}

TEST(Problem86, solution) {
    auto res = problem86::solve();
    EXPECT_EQ(res, 1818);
}