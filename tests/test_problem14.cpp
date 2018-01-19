//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../src/problems/1-50/14/problem14.hpp"

using problems::problem14;

TEST(Problem14, solution) {
    auto res = problem14::solve();
    EXPECT_EQ(res, 837799);
}