//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/54/problem54.hpp"

using problems::problem54;

TEST(Problem54, solution) {
    auto res = problem54::solve();
    EXPECT_EQ(res, 376);
}