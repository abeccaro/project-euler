//
// Created by Alex Beccaro on 07/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/117/problem117.hpp"

BOOST_AUTO_TEST_SUITE( Problem117 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem117::solve(5);
        BOOST_CHECK_EQUAL(res, 15);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem117::solve();
        BOOST_CHECK_EQUAL(res, 100808458960497);
    }

BOOST_AUTO_TEST_SUITE_END()