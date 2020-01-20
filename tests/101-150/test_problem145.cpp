//
// Created by Alex Beccaro on 16/01/2020.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/145/problem145.hpp"

BOOST_AUTO_TEST_SUITE( Problem145 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem145::solve(3);
        BOOST_CHECK_EQUAL(res, 120);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem145::solve();
        BOOST_CHECK_EQUAL(res, 608720);
    }

BOOST_AUTO_TEST_SUITE_END()