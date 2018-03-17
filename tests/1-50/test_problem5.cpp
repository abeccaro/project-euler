//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/5/problem5.hpp"

BOOST_AUTO_TEST_SUITE( Problem5 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem5::solve(10);
        BOOST_CHECK_EQUAL(res, 2520);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem5::solve();
        BOOST_CHECK_EQUAL(res, 232792560);
    }

BOOST_AUTO_TEST_SUITE_END()