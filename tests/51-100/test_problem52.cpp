//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/52/problem52.hpp"

using problems::problem52;

TEST(Problem52, example) {
    auto res = problem52::solve(2);
    EXPECT_EQ(res, 125874);
}

TEST(Problem52, solution) {
    auto res = problem52::solve();
    EXPECT_EQ(res, 142857);
}