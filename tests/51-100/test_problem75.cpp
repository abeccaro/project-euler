//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/51-100/75/problem75.hpp"

BOOST_AUTO_TEST_SUITE( Problem75 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem75::solve(48);
        BOOST_CHECK_EQUAL(res, 6);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem75::solve();
        BOOST_CHECK_EQUAL(res, 161667);
    }

BOOST_AUTO_TEST_SUITE_END()