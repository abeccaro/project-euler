//
// Created by Alex Beccaro on 20/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/121/problem121.hpp"

BOOST_AUTO_TEST_SUITE( Problem121 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem121::solve(4);
        BOOST_CHECK_EQUAL(res, 10);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem121::solve();
        BOOST_CHECK_EQUAL(res, 2269);
    }

BOOST_AUTO_TEST_SUITE_END()