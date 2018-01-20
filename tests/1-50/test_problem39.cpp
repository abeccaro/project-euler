//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/39/problem39.hpp"

using problems::problem39;

TEST(Problem39, solution) {
    auto res = problem39::solve();
    EXPECT_EQ(res, 840);
}