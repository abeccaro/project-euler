//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/12/problem12.hpp"

BOOST_AUTO_TEST_SUITE( Problem12 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem12::solve(5);
        BOOST_CHECK_EQUAL(res, 28);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem12::solve();
        BOOST_CHECK_EQUAL(res, 76576500);
    }

BOOST_AUTO_TEST_SUITE_END()