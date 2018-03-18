//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/34/problem34.hpp"

BOOST_AUTO_TEST_SUITE( Problem34 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem34::solve();
        BOOST_CHECK_EQUAL(res, 40730);
    }

BOOST_AUTO_TEST_SUITE_END()