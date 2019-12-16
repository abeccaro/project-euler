//
// Created by Alex Beccaro on 08/12/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/141/problem141.hpp"

BOOST_AUTO_TEST_SUITE( Problem141 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem141::solve(100000);
        BOOST_CHECK_EQUAL(res, 124657);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem141::solve();
        BOOST_CHECK_EQUAL(res, 878454337159);
    }

BOOST_AUTO_TEST_SUITE_END()