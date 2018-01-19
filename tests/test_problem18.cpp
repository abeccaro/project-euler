//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../src/problems/1-50/18/problem18.hpp"

using problems::problem18;

TEST(Problem18, solution) {
    auto res = problem18::solve();
    EXPECT_EQ(res, 1074);
}