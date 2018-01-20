//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/47/problem47.hpp"

using problems::problem47;

TEST(Problem47, example1) {
    auto res = problem47::solve(2,2);
    EXPECT_EQ(res, 14);
}

TEST(Problem47, example2) {
    auto res = problem47::solve(3,3);
    EXPECT_EQ(res, 644);
}

TEST(Problem47, solution) {
    auto res = problem47::solve();
    EXPECT_EQ(res, 134043);
}