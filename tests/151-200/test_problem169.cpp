//
// Created by Alex Beccaro on 08/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/169/problem169.hpp"

BOOST_AUTO_TEST_SUITE( Problem169 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem169::solve(10);
        BOOST_CHECK_EQUAL(res, 5);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem169::solve();
        BOOST_CHECK_EQUAL(res, 178653872807);
    }

BOOST_AUTO_TEST_SUITE_END()