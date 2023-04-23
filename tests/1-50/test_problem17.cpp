//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/17/problem17.hpp"

BOOST_AUTO_TEST_SUITE( Problem17 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem17::solve(5);
        BOOST_CHECK_EQUAL(res, 19);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem17::solve();
        BOOST_CHECK_EQUAL(res, 21124);
    }

BOOST_AUTO_TEST_SUITE_END()