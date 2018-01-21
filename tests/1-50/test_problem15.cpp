//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/15/problem15.hpp"

using problems::problem15;

TEST(Problem15, example) {
    auto res = problem15::solve(2,2);
    EXPECT_EQ(res, 6);
}

TEST(Problem15, solution) {
    auto res = problem15::solve();
    EXPECT_EQ(res, 137846528820);
}