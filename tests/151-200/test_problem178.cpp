//
// Created by Alex Beccaro on 28/04/2026.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/178/problem178.hpp"

BOOST_AUTO_TEST_SUITE( Problem178 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem178::solve(40);
        BOOST_CHECK_EQUAL(res, 126461847755);
    }

BOOST_AUTO_TEST_SUITE_END()