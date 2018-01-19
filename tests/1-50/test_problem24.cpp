//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/24/problem24.hpp"

using problems::problem24;

TEST(Problem24, examples) {
    vector<uint> base = {0,1,2};
    vector<uint> sol = base;
    for (uint i = 1; i <= 6; i++) {
        EXPECT_EQ(problem24::solve(base, i), sol);
        std::next_permutation(sol.begin(), sol.end());
    }
}

TEST(Problem24, solution) {
    auto res = problem24::solve();
    vector<uint> sol = {2,7,8,3,9,1,5,4,6,0};
    EXPECT_EQ(res, sol);
}