//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/6/problem6.hpp"

BOOST_AUTO_TEST_SUITE( Problem6 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem6::solve(10);
        BOOST_CHECK_EQUAL(res, 2640);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem6::solve();
        BOOST_CHECK_EQUAL(res, 25164150);
    }

BOOST_AUTO_TEST_SUITE_END()