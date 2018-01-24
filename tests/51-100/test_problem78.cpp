//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/78/problem78.hpp"

using problems::problem78;

TEST(Problem78, example) {
    auto res = problem78::solve(7);
    EXPECT_EQ(res, 5);
}

TEST(Problem78, solution) {
    auto res = problem78::solve();
    EXPECT_EQ(res, 55374);
}