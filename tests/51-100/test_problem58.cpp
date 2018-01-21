//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/58/problem58.hpp"

using problems::problem58;

TEST(Problem58, solution) {
    auto res = problem58::solve();
    EXPECT_EQ(res, 26241);
}