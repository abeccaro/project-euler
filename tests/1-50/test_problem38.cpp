//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/38/problem38.hpp"

using problems::problem38;

TEST(Problem38, solution) {
    auto res = problem38::solve();
    EXPECT_EQ(res, 932718654);
}