//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/31/problem31.hpp"

using problems::problem31;

TEST(Problem31, solution) {
    auto res = problem31::solve();
    EXPECT_EQ(res, 73682);
}