//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/3/problem3.hpp"

using problems::problem3;

TEST(Problem3, example) {
    auto res = problem3::solve(13195);
    EXPECT_EQ(res, 29);
}

TEST(Problem3, solution) {
    auto res = problem3::solve();
    EXPECT_EQ(res, 6857);
}