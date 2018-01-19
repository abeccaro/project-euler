//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../src/problems/1-50/19/problem19.hpp"

using problems::problem19;

TEST(Problem19, solution) {
    auto res = problem19::solve();
    EXPECT_EQ(res, 171);
}