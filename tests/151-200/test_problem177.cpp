//
// Created by Alex Beccaro on 26/04/2026.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/177/problem177.hpp"

BOOST_AUTO_TEST_SUITE( Problem177 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem177::solve();
        BOOST_CHECK_EQUAL(res, 129325);
    }

BOOST_AUTO_TEST_SUITE_END()