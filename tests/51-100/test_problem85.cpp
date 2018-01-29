//
// Created by Alex Beccaro on 29/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/85/problem85.hpp"

using problems::problem85;

TEST(Problem85, solution) {
    auto res = problem85::solve();
    EXPECT_EQ(res, 2772);
}