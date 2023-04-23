//
// Created by Alex Beccaro on 23/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/126/problem126.hpp"

BOOST_AUTO_TEST_SUITE( Problem126 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem126::solve(10);
        BOOST_CHECK_EQUAL(res, 154);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem126::solve();
        BOOST_CHECK_EQUAL(res, 18522);
    }

BOOST_AUTO_TEST_SUITE_END()