//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/9/problem9.hpp"

BOOST_AUTO_TEST_SUITE( Problem9 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem9::solve(12);
        BOOST_CHECK_EQUAL(res, 60);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem9::solve();
        BOOST_CHECK_EQUAL(res, 31875000);
    }

BOOST_AUTO_TEST_SUITE_END()