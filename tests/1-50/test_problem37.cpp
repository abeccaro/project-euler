//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/37/problem37.hpp"

using problems::problem37;

TEST(Problem37, solution) {
    auto res = problem37::solve();
    EXPECT_EQ(res, 748317);
}