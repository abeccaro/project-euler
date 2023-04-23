//
// Created by Alex Beccaro on 16/01/2020.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/146/problem146.hpp"

BOOST_AUTO_TEST_SUITE( Problem146 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem146::solve(1000000);
        BOOST_CHECK_EQUAL(res, 1242490);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem146::solve();
        BOOST_CHECK_EQUAL(res, 676333270);
    }

BOOST_AUTO_TEST_SUITE_END()