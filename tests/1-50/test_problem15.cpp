//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/15/problem15.hpp"

BOOST_AUTO_TEST_SUITE( Problem15 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem15::solve(2, 2);
        BOOST_CHECK_EQUAL(res, 6);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem15::solve();
        BOOST_CHECK_EQUAL(res, 137846528820);
    }

BOOST_AUTO_TEST_SUITE_END()