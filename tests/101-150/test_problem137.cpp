//
// Created by Alex Beccaro on 06/12/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/137/problem137.hpp"

BOOST_AUTO_TEST_SUITE( Problem137 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem137::solve(10);
        BOOST_CHECK_EQUAL(res, 74049690);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem137::solve();
        BOOST_CHECK_EQUAL(res, 1120149658760);
    }

BOOST_AUTO_TEST_SUITE_END()