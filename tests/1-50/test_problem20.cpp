//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/20/problem20.hpp"

BOOST_AUTO_TEST_SUITE( Problem20 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem20::solve(10);
        BOOST_CHECK_EQUAL(res, 27);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem20::solve();
        BOOST_CHECK_EQUAL(res, 648);
    }

BOOST_AUTO_TEST_SUITE_END()