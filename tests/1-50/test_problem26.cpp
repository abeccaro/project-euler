//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/26/problem26.hpp"

BOOST_AUTO_TEST_SUITE( Problem26 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem26::solve(10);
        BOOST_CHECK_EQUAL(res, 7);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem26::solve();
        BOOST_CHECK_EQUAL(res, 983);
    }

BOOST_AUTO_TEST_SUITE_END()