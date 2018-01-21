//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/42/problem42.hpp"

using problems::problem42;

TEST(Problem42, solution) {
    auto res = problem42::solve();
    EXPECT_EQ(res, 162);
}