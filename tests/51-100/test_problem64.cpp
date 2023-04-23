//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/64/problem64.hpp"

BOOST_AUTO_TEST_SUITE( Problem64 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem64::solve(13);
        BOOST_CHECK_EQUAL(res, 4);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem64::solve();
        BOOST_CHECK_EQUAL(res, 1322);
    }

BOOST_AUTO_TEST_SUITE_END()