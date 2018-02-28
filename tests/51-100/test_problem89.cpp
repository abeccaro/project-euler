//
// Created by Alex Beccaro on 28/02/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/89/problem89.hpp"

using problems::problem89;

TEST(Problem89, solution) {
    auto res = problem89::solve();
    EXPECT_EQ(res, 743);
}