//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/40/problem40.hpp"

using problems::problem40;

TEST(Problem40, solution) {
    auto res = problem40::solve();
    EXPECT_EQ(res, 210);
}