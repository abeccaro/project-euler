//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/32/problem32.hpp"

using problems::problem32;

TEST(Problem32, solution) {
    auto res = problem32::solve();
    EXPECT_EQ(res, 45228);
}