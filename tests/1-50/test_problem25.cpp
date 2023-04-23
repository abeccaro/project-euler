//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/25/problem25.hpp"

BOOST_AUTO_TEST_SUITE( Problem25 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem25::solve(3);
        BOOST_CHECK_EQUAL(res, 12);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem25::solve();
        BOOST_CHECK_EQUAL(res, 4782);
    }

BOOST_AUTO_TEST_SUITE_END()