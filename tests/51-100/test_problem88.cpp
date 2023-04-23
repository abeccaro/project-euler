//
// Created by Alex Beccaro on 27/02/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/88/problem88.hpp"

BOOST_AUTO_TEST_SUITE( Problem88 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem88::solve(6);
        BOOST_CHECK_EQUAL(res, 30);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem88::solve(12);
        BOOST_CHECK_EQUAL(res, 61);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem88::solve();
        BOOST_CHECK_EQUAL(res, 7587457);
    }

BOOST_AUTO_TEST_SUITE_END()