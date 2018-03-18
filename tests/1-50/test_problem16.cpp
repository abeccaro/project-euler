//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/16/problem16.hpp"

BOOST_AUTO_TEST_SUITE( Problem16 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem16::solve(15);
        BOOST_CHECK_EQUAL(res, 26);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem16::solve();
        BOOST_CHECK_EQUAL(res, 1366);
    }

BOOST_AUTO_TEST_SUITE_END()