//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/51-100/57/problem57.hpp"

BOOST_AUTO_TEST_SUITE( Problem57 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res7 = problems::problem57::solve(7);
        BOOST_CHECK_EQUAL(res7, 0);
        auto res8 = problems::problem57::solve(8);
        BOOST_CHECK_EQUAL(res8, 1);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem57::solve();
        BOOST_CHECK_EQUAL(res, 153);
    }

BOOST_AUTO_TEST_SUITE_END()