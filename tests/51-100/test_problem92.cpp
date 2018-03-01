//
// Created by Alex Beccaro on 01/03/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/92/problem92.hpp"

using problems::problem92;

TEST(Problem92, solution) {
    auto res = problem92::solve(10000000);
    EXPECT_EQ(res, 8581146);
}