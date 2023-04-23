//
// Created by Alex Beccaro on 22/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/124/problem124.hpp"

BOOST_AUTO_TEST_SUITE( Problem124 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem124::solve(10, 4);
        BOOST_CHECK_EQUAL(res, 8);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem124::solve(10, 6);
        BOOST_CHECK_EQUAL(res, 9);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem124::solve();
        BOOST_CHECK_EQUAL(res, 21417);
    }

BOOST_AUTO_TEST_SUITE_END()