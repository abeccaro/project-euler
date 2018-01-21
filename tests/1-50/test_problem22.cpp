//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/22/problem22.hpp"

using problems::problem22;

TEST(Problem22, solution) {
    auto res = problem22::solve();
    EXPECT_EQ(res, 871198282);
}