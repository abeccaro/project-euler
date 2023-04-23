//
// Created by Alex Beccaro on 17/09/2022.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/160/problem160.hpp"

BOOST_AUTO_TEST_SUITE( Problem160 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem160::solve(9);
        BOOST_CHECK_EQUAL(res, 36288);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem160::solve(10);
        BOOST_CHECK_EQUAL(res, 36288);
    }

    BOOST_AUTO_TEST_CASE( Example3 ) {
        auto res = problems::problem160::solve(20);
        BOOST_CHECK_EQUAL(res, 17664);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem160::solve();
        BOOST_CHECK_EQUAL(res, 16576);
    }

BOOST_AUTO_TEST_SUITE_END()