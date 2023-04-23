//
// Created by Alex Beccaro on 03/12/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/106/problem106.hpp"

BOOST_AUTO_TEST_SUITE( Problem106 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem106::solve(4);
        BOOST_CHECK_EQUAL(res, 1);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem106::solve(7);
        BOOST_CHECK_EQUAL(res, 70);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem106::solve();
        BOOST_CHECK_EQUAL(res, 21384);
    }

BOOST_AUTO_TEST_SUITE_END()