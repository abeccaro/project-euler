//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/76/problem76.hpp"

BOOST_AUTO_TEST_SUITE( Problem76 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem76::solve(5);
        BOOST_CHECK_EQUAL(res, 6);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem76::solve();
        BOOST_CHECK_EQUAL(res, 190569291);
    }

BOOST_AUTO_TEST_SUITE_END()