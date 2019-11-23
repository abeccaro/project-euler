//
// Created by Alex Beccaro on 23/01/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/127/problem127.hpp"

BOOST_AUTO_TEST_SUITE( Problem127 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem127::solve(1000);
        BOOST_CHECK_EQUAL(res, 12523);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem127::solve();
        BOOST_CHECK_EQUAL(res, 18407904);
    }

BOOST_AUTO_TEST_SUITE_END()