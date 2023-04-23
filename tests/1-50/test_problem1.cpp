//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/1/problem1.hpp"

BOOST_AUTO_TEST_SUITE( Problem1 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem1::solve(10);
        BOOST_CHECK_EQUAL(res, 23);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem1::solve();
        BOOST_CHECK_EQUAL(res, 233168);
    }

BOOST_AUTO_TEST_SUITE_END()