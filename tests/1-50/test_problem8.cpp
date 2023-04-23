//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/8/problem8.hpp"

BOOST_AUTO_TEST_SUITE( Problem8 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem8::solve(4);
        BOOST_CHECK_EQUAL(res, 5832);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem8::solve();
        BOOST_CHECK_EQUAL(res, 23514624000);
    }

BOOST_AUTO_TEST_SUITE_END()