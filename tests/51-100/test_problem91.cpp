//
// Created by Alex Beccaro on 28/02/18.
//

#include "../../src/problems/51-100/91/problem91.hpp"

BOOST_AUTO_TEST_SUITE( Problem91 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem91::solve(2, 2);
        BOOST_CHECK_EQUAL(res, 14);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem91::solve();
        BOOST_CHECK_EQUAL(res, 14234);
    }

BOOST_AUTO_TEST_SUITE_END()