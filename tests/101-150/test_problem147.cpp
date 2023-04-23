//
// Created by Alex Beccaro on 08/12/2020.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/147/problem147.hpp"

BOOST_AUTO_TEST_SUITE( Problem147 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem147::solve(3, 2);
        BOOST_CHECK_EQUAL(res, 72);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem147::solve();
        BOOST_CHECK_EQUAL(res, 846910284);
    }

BOOST_AUTO_TEST_SUITE_END()