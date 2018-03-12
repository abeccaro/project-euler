//
// Created by Alex Beccaro on 12/03/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/96/problem96.hpp"

using problems::problem96;

TEST(Problem96, solution) {
    auto res = problem96::solve();
    EXPECT_EQ(res, 24702);
}