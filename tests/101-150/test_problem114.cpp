//
// Created by Alex Beccaro on 07/01/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/114/problem114.hpp"

BOOST_AUTO_TEST_SUITE( Problem114 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem114::solve(7);
        BOOST_CHECK_EQUAL(res, 17);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem114::solve();
        BOOST_CHECK_EQUAL(res, 16475640049);
    }

BOOST_AUTO_TEST_SUITE_END()