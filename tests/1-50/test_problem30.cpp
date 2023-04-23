//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/30/problem30.hpp"

BOOST_AUTO_TEST_SUITE( Problem30 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem30::solve(4);
        BOOST_CHECK_EQUAL(res, 19316);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem30::solve();
        BOOST_CHECK_EQUAL(res, 443839);
    }

BOOST_AUTO_TEST_SUITE_END()