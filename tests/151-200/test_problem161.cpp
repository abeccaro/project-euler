//
// Created by Alex Beccaro on 23/04/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/161/problem161.hpp"

BOOST_AUTO_TEST_SUITE( Problem161 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem161::solve(2, 9);
        BOOST_CHECK_EQUAL(res, 41);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem161::solve(9,12);
        BOOST_CHECK_EQUAL(res, 20574308184277971);
    }

BOOST_AUTO_TEST_SUITE_END()