//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/47/problem47.hpp"

BOOST_AUTO_TEST_SUITE( Problem47 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem47::solve(2, 2);
        BOOST_CHECK_EQUAL(res, 14);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem47::solve(3, 3);
        BOOST_CHECK_EQUAL(res, 644);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem47::solve();
        BOOST_CHECK_EQUAL(res, 134043);
    }

BOOST_AUTO_TEST_SUITE_END()