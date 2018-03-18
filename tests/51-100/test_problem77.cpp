//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/77/problem77.hpp"

BOOST_AUTO_TEST_SUITE( Problem77 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem77::solve(4);
        BOOST_CHECK_EQUAL(res, 10);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem77::solve();
        BOOST_CHECK_EQUAL(res, 71);
    }

BOOST_AUTO_TEST_SUITE_END()