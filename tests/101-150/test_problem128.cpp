//
// Created by Alex Beccaro on 23/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/128/problem128.hpp"

BOOST_AUTO_TEST_SUITE( Problem128 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem128::solve(10);
        BOOST_CHECK_EQUAL(res, 271);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem128::solve();
        BOOST_CHECK_EQUAL(res, 14516824220);
    }

BOOST_AUTO_TEST_SUITE_END()