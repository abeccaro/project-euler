//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/42/problem42.hpp"

BOOST_AUTO_TEST_SUITE( Problem42 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem42::solve();
        BOOST_CHECK_EQUAL(res, 162);
    }

BOOST_AUTO_TEST_SUITE_END()