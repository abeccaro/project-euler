//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../src/problems/1-50/8/problem8.hpp"

using problems::problem8;

TEST(Problem8, example) {
    auto res = problem8::solve(4);
    EXPECT_EQ(res, 5832);
}

TEST(Problem8, solution) {
    auto res = problem8::solve();
    EXPECT_EQ(res, 23514624000);
}