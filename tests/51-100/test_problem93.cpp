//
// Created by Alex Beccaro on 01/03/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/93/problem93.hpp"

using problems::problem93;

TEST(Problem93, solution) {
    auto res = problem93::solve();
    EXPECT_EQ(res, "1258");
}