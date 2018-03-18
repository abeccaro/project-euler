//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/65/problem65.hpp"

BOOST_AUTO_TEST_SUITE( Problem65 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem65::solve(10);
        BOOST_CHECK_EQUAL(res, 17);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem65::solve();
        BOOST_CHECK_EQUAL(res, 272);
    }

BOOST_AUTO_TEST_SUITE_END()