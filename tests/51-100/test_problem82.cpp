//
// Created by Alex Beccaro on 25/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/82/problem82.hpp"

using problems::problem82;

TEST(Problem82, solution) {
    auto res = problem82::solve();
    EXPECT_EQ(res, 260324);
}