//
// Created by Alex Beccaro on 25/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/132/problem132.hpp"

BOOST_AUTO_TEST_SUITE( Problem132 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem132::solve(1, 4);
        BOOST_CHECK_EQUAL(res, 9414);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem132::solve();
        BOOST_CHECK_EQUAL(res, 843296);
    }

BOOST_AUTO_TEST_SUITE_END()