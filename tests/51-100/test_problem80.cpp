//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/51-100/80/problem80.hpp"

BOOST_AUTO_TEST_SUITE( Problem80 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem80::solve(2);
        BOOST_CHECK_EQUAL(res, 475);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem80::solve();
        BOOST_CHECK_EQUAL(res, 40886);
    }

BOOST_AUTO_TEST_SUITE_END()