//
// Created by Alex Beccaro on 25/02/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/84/problem84.hpp"

BOOST_AUTO_TEST_SUITE( Problem84 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem84::solve(6);
        BOOST_CHECK_EQUAL(res, "102400");
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem84::solve();
        BOOST_CHECK_EQUAL(res, "101524");
    }

BOOST_AUTO_TEST_SUITE_END()