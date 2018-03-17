//
// Created by Alex Beccaro on 12/03/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/97/problem97.hpp"

using problems::problem97;

TEST(Problem97, solution) {
    auto res = problem97::solve();
    EXPECT_EQ(res, "8739992577");
}