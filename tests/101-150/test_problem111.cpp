//
// Created by Alex Beccaro on 06/12/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/111/problem111.hpp"

BOOST_AUTO_TEST_SUITE( Problem111 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem111::solve(4);
        BOOST_CHECK_EQUAL(res, 273700);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem111::solve();
        BOOST_CHECK_EQUAL(res, 612407567715);
    }

BOOST_AUTO_TEST_SUITE_END()