//
// Created by Alex Beccaro on 24/01/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/130/problem130.hpp"

BOOST_AUTO_TEST_SUITE( Problem130 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem130::solve(5);
        BOOST_CHECK_EQUAL(res, 1985);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem130::solve();
        BOOST_CHECK_EQUAL(res, 149253);
    }

BOOST_AUTO_TEST_SUITE_END()