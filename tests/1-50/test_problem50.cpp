//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/50/problem50.hpp"

BOOST_AUTO_TEST_SUITE( Problem50 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem50::solve(100);
        BOOST_CHECK_EQUAL(res, 41);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem50::solve();
        BOOST_CHECK_EQUAL(res, 997651);
    }

BOOST_AUTO_TEST_SUITE_END()