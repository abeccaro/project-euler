//
// Created by Alex Beccaro on 07/03/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/95/problem95.hpp"

using problems::problem95;

TEST(Problem95, solution) {
    auto res = problem95::solve();
    EXPECT_EQ(res, 14316);
}