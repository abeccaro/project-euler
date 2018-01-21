//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/61/problem61.hpp"

using problems::problem61;

TEST(Problem61, example) {
    auto res = problem61::solve(3);
    EXPECT_EQ(res, 19291);
}

TEST(Problem61, solution) {
    auto res = problem61::solve();
    EXPECT_EQ(res, 28684);
}