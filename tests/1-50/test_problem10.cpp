//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/10/problem10.hpp"

using problems::problem10;

TEST(Problem10, example) {
    auto res = problem10::solve(10);
    EXPECT_EQ(res, 17);
}

TEST(Problem10, solution) {
    auto res = problem10::solve();
    EXPECT_EQ(res, 142913828922);
}