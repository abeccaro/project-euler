//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/60/problem60.hpp"

using problems::problem60;

TEST(Problem60, example) {
    auto res = problem60::solve(4);
    EXPECT_EQ(res, 792);
}

TEST(Problem60, solution) {
    auto res = problem60::solve();
    EXPECT_EQ(res, 26033);
}