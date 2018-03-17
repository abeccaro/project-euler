//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/51-100/52/problem52.hpp"

BOOST_AUTO_TEST_SUITE( Problem52 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem52::solve(2);
        BOOST_CHECK_EQUAL(res, 125874);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem52::solve();
        BOOST_CHECK_EQUAL(res, 142857);
    }

BOOST_AUTO_TEST_SUITE_END()