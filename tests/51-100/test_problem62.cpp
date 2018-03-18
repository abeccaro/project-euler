//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/62/problem62.hpp"

BOOST_AUTO_TEST_SUITE( Problem62 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem62::solve(3);
        BOOST_CHECK_EQUAL(res, 41063625);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem62::solve();
        BOOST_CHECK_EQUAL(res, 127035954683);
    }

BOOST_AUTO_TEST_SUITE_END()