//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/65/problem65.hpp"

using problems::problem65;

TEST(Problem65, example) {
    auto res = problem65::solve(10);
    EXPECT_EQ(res, 17);
}

TEST(Problem65, solution) {
    auto res = problem65::solve();
    EXPECT_EQ(res, 272);
}