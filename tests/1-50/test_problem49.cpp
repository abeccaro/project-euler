//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/49/problem49.hpp"

using problems::problem49;

TEST(Problem49, solution) {
    auto res = problem49::solve();
    EXPECT_EQ(res, 296962999629);
}