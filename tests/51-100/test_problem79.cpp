//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/79/problem79.hpp"

using problems::problem79;

TEST(Problem79, solution) {
    auto res = problem79::solve();
    vector<uint> sol = {7, 3, 1, 6, 2, 8, 9, 0};
    EXPECT_EQ(res, sol);
}