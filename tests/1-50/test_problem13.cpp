//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/13/problem13.hpp"

using problems::problem13;

TEST(Problem13, solution) {
    auto res = problem13::solve();
    vector<unsigned int> expected = {5, 5, 3, 7, 3, 7, 6, 2, 3, 0};
    EXPECT_EQ(res, expected);
}