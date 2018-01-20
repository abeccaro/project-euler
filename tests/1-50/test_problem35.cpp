//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/35/problem35.hpp"

using problems::problem35;

TEST(Problem35, example) {
    auto res = problem35::solve(100);
    EXPECT_EQ(res, 13);
}

TEST(Problem35, solution) {
    auto res = problem35::solve();
    EXPECT_EQ(res, 55);
}