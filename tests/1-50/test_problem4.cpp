//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/4/problem4.hpp"

BOOST_AUTO_TEST_SUITE( Problem4 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem4::solve(2);
        BOOST_CHECK_EQUAL(res, 9009);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem4::solve();
        BOOST_CHECK_EQUAL(res, 906609);
    }

BOOST_AUTO_TEST_SUITE_END()