//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/7/problem7.hpp"

BOOST_AUTO_TEST_SUITE( Problem7 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem7::solve(6);
        BOOST_CHECK_EQUAL(res, 13);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem7::solve();
        BOOST_CHECK_EQUAL(res, 104743);
    }

BOOST_AUTO_TEST_SUITE_END()