//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/72/problem72.hpp"

using problems::problem72;

TEST(Problem72, example) {
    auto res = problem72::solve(8);
    EXPECT_EQ(res, 21);
}

TEST(Problem72, solution) {
    auto res = problem72::solve();
    EXPECT_EQ(res, 303963552391);
}