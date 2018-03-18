//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/69/problem69.hpp"

BOOST_AUTO_TEST_SUITE( Problem69 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem69::solve(10);
        BOOST_CHECK_EQUAL(res, 6);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem69::solve();
        BOOST_CHECK_EQUAL(res, 510510);
    }

BOOST_AUTO_TEST_SUITE_END()