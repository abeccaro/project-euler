//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/29/problem29.hpp"

BOOST_AUTO_TEST_SUITE( Problem29 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem29::solve(5, 5);
        BOOST_CHECK_EQUAL(res, 15);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem29::solve();
        BOOST_CHECK_EQUAL(res, 9183);
    }

BOOST_AUTO_TEST_SUITE_END()