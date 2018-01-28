//
// Created by Alex Beccaro on 25/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/83/problem83.hpp"

using problems::problem83;

TEST(Problem83, solution) {
    auto res = problem83::solve();
    EXPECT_EQ(res, 425185);
}