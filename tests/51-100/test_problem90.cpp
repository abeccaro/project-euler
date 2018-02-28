//
// Created by Alex Beccaro on 28/02/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/90/problem90.hpp"

using problems::problem90;

TEST(Problem90, solution) {
    auto res = problem90::solve();
    EXPECT_EQ(res, 1217);
}