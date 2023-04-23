//
// Created by Alex Beccaro on 09/12/2020.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/148/problem148.hpp"

BOOST_AUTO_TEST_SUITE( Problem148 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem148::solve(100);
        BOOST_CHECK_EQUAL(res, 2361);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem148::solve();
        BOOST_CHECK_EQUAL(res, 2129970655314432);
    }

BOOST_AUTO_TEST_SUITE_END()