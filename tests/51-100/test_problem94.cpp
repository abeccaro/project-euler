//
// Created by Alex Beccaro on 02/03/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/94/problem94.hpp"

using problems::problem94;

TEST(Problem94, solution) {
    auto res = problem94::solve();
    EXPECT_EQ(res, 518408346);
}