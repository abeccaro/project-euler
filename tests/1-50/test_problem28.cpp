//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/28/problem28.hpp"

using problems::problem28;

TEST(Problem28, solution) {
    auto res = problem28::solve();
    EXPECT_EQ(res, 669171001);
}