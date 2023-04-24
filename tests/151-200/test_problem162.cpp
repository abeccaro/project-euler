//
// Created by Alex Beccaro on 24/04/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/162/problem162.hpp"

BOOST_AUTO_TEST_SUITE( Problem162 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem162::solve(3);
        BOOST_CHECK_EQUAL(res, "4");
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem162::solve(16);
        BOOST_CHECK_EQUAL(res, "3D58725572C62302");
    }

BOOST_AUTO_TEST_SUITE_END()