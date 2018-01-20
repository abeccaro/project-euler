//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/44/problem44.hpp"

using problems::problem44;

TEST(Problem44, solution) {
    auto res = problem44::solve();
    EXPECT_EQ(res, 5482660);
}