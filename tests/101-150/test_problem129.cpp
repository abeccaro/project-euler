//
// Created by Alex Beccaro on 23/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/129/problem129.hpp"

BOOST_AUTO_TEST_SUITE( Problem129 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem129::solve(10);
        BOOST_CHECK_EQUAL(res, 17);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem129::solve();
        BOOST_CHECK_EQUAL(res, 1000023);
    }

BOOST_AUTO_TEST_SUITE_END()