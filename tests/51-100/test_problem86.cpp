//
// Created by Alex Beccaro on 25/02/18.
//

#include "../../src/problems/51-100/86/problem86.hpp"

BOOST_AUTO_TEST_SUITE( Problem86 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem86::solve(2000);
        BOOST_CHECK_EQUAL(res, 100);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem86::solve();
        BOOST_CHECK_EQUAL(res, 1818);
    }

BOOST_AUTO_TEST_SUITE_END()