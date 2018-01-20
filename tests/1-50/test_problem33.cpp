//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/33/problem33.hpp"

using problems::problem33;

TEST(Problem33, solution) {
    auto res = problem33::solve();
    EXPECT_EQ(res, 100);
}