//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/11/problem11.hpp"

using problems::problem11;

TEST(Problem11, solution) {
    auto res = problem11::solve();
    EXPECT_EQ(res, 70600674);
}