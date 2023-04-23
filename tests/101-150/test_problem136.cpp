//
// Created by Alex Beccaro on 05/12/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/136/problem136.hpp"

BOOST_AUTO_TEST_SUITE( Problem136 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem136::solve(100);
        BOOST_CHECK_EQUAL(res, 25);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem136::solve();
        BOOST_CHECK_EQUAL(res, 2544559);
    }

BOOST_AUTO_TEST_SUITE_END()