//
// Created by Alex Beccaro on 27/12/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/112/problem112.hpp"

BOOST_AUTO_TEST_SUITE( Problem112 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem112::solve(0.5);
        BOOST_CHECK_EQUAL(res, 538);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem112::solve(0.9);
        BOOST_CHECK_EQUAL(res, 21780);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem112::solve();
        BOOST_CHECK_EQUAL(res, 1587000);
    }

BOOST_AUTO_TEST_SUITE_END()