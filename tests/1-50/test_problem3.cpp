//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/3/problem3.hpp"

BOOST_AUTO_TEST_SUITE( Problem3 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem3::solve(13195);
        BOOST_CHECK_EQUAL(res, 29);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem3::solve();
        BOOST_CHECK_EQUAL(res, 6857);
    }

BOOST_AUTO_TEST_SUITE_END()