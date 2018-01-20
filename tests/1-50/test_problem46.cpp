//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/46/problem46.hpp"

using problems::problem46;

TEST(Problem46, solution) {
    auto res = problem46::solve();
    EXPECT_EQ(res, 5777);
}