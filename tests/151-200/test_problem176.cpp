//
// Created by Alex Beccaro on 19/03/2025.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/176/problem176.hpp"

BOOST_AUTO_TEST_SUITE( Problem176 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem176::solve(4);
        BOOST_CHECK_EQUAL(res, 12);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem176::solve();
        BOOST_CHECK_EQUAL(res, 96818198400000);
    }

BOOST_AUTO_TEST_SUITE_END()