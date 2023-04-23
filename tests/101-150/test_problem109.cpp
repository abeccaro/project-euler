//
// Created by Alex Beccaro on 27/12/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/109/problem109.hpp"

BOOST_AUTO_TEST_SUITE( Problem109 )

    BOOST_AUTO_TEST_CASE( All ) {
        auto res = problems::problem109::solve(171);
        BOOST_CHECK_EQUAL(res, 42336);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem109::solve();
        BOOST_CHECK_EQUAL(res, 38182);
    }

BOOST_AUTO_TEST_SUITE_END()