//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/71/problem71.hpp"

BOOST_AUTO_TEST_SUITE( Problem71 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem71::solve(8);
        BOOST_CHECK_EQUAL(res, 2);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem71::solve();
        BOOST_CHECK_EQUAL(res, 428570);
    }

BOOST_AUTO_TEST_SUITE_END()