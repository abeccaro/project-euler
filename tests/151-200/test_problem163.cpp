//
// Created by Alex Beccaro on 29/04/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/163/problem163.hpp"

BOOST_AUTO_TEST_SUITE( Problem163 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem163::solve(1);
        BOOST_CHECK_EQUAL(res, 16);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem163::solve(2);
        BOOST_CHECK_EQUAL(res, 104);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem163::solve();
        BOOST_CHECK_EQUAL(res, 343047);
    }

BOOST_AUTO_TEST_SUITE_END()