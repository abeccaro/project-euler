//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/23/problem23.hpp"

using problems::problem23;

TEST(Problem23, solution) {
    auto res = problem23::solve();
    EXPECT_EQ(res, 4179871);
}