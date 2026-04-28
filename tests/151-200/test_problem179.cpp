//
// Created by Alex Beccaro on 28/04/2026.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/179/problem179.hpp"

BOOST_AUTO_TEST_SUITE( Problem179 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem179::solve(10000000);
        BOOST_CHECK_EQUAL(res, 986262);
    }

BOOST_AUTO_TEST_SUITE_END()