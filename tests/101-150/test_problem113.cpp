//
// Created by Alex Beccaro on 28/12/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/113/problem113.hpp"

BOOST_AUTO_TEST_SUITE( Problem113 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem113::solve(6);
        BOOST_CHECK_EQUAL(res, 12951);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem113::solve(10);
        BOOST_CHECK_EQUAL(res, 277032);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem113::solve(100);
        BOOST_CHECK_EQUAL(res, 51161058134250);
    }

BOOST_AUTO_TEST_SUITE_END()