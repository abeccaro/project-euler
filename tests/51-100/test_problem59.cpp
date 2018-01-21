//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/59/problem59.hpp"

using problems::problem59;

TEST(Problem59, solution) {
    auto res = problem59::solve();
    EXPECT_EQ(res, 107359);
}