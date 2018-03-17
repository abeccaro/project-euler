//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/45/problem45.hpp"

BOOST_AUTO_TEST_SUITE( Problem45 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem45::solve(2);
        BOOST_CHECK_EQUAL(res, 40755);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem45::solve();
        BOOST_CHECK_EQUAL(res, 1533776805);
    }

BOOST_AUTO_TEST_SUITE_END()