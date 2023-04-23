//
// Created by Alex Beccaro on 22/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/125/problem125.hpp"

BOOST_AUTO_TEST_SUITE( Problem125 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem125::solve(1000);
        BOOST_CHECK_EQUAL(res, 4164);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem125::solve();
        BOOST_CHECK_EQUAL(res, 2906969179);
    }

BOOST_AUTO_TEST_SUITE_END()