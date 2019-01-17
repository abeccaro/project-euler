//
// Created by Alex Beccaro on 17/01/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/119/problem119.hpp"

BOOST_AUTO_TEST_SUITE( Problem119 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem119::solve(2);
        BOOST_CHECK_EQUAL(res, 512);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem119::solve(10);
        BOOST_CHECK_EQUAL(res, 614656);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem119::solve();
        BOOST_CHECK_EQUAL(res, 248155780267521);
    }

BOOST_AUTO_TEST_SUITE_END()