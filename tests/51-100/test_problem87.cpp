//
// Created by Alex Beccaro on 26/02/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/87/problem87.hpp"

BOOST_AUTO_TEST_SUITE( Problem87 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem87::solve(50);
        BOOST_CHECK_EQUAL(res, 4);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem87::solve();
        BOOST_CHECK_EQUAL(res, 1097343);
    }

BOOST_AUTO_TEST_SUITE_END()