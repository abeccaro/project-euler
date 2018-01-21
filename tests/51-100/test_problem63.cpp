//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/63/problem63.hpp"

using problems::problem63;

TEST(Problem63, solution) {
    auto res = problem63::solve();
    EXPECT_EQ(res, 49);
}