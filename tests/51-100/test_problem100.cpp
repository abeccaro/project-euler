//
// Created by Alex Beccaro on 12/03/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/100/problem100.hpp"

BOOST_AUTO_TEST_SUITE( Problem100 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem100::solve(4);
        BOOST_CHECK_EQUAL(res, 15);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem100::solve(21);
        BOOST_CHECK_EQUAL(res, 85);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem100::solve();
        BOOST_CHECK_EQUAL(res, 756872327473);
    }

BOOST_AUTO_TEST_SUITE_END()