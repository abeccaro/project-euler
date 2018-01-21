//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/62/problem62.hpp"

using problems::problem62;

TEST(Problem62, example) {
    auto res = problem62::solve(3);
    EXPECT_EQ(res, 41063625);
}

TEST(Problem62, solution) {
    auto res = problem62::solve();
    EXPECT_EQ(res, 127035954683);
}