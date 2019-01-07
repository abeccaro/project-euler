//
// Created by Alex Beccaro on 07/01/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/116/problem116.hpp"

BOOST_AUTO_TEST_SUITE( Problem116 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem116::solve(5);
        BOOST_CHECK_EQUAL(res, 12);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem116::solve();
        BOOST_CHECK_EQUAL(res, 20492570929);
    }

BOOST_AUTO_TEST_SUITE_END()