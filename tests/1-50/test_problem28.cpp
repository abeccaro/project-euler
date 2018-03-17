//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/28/problem28.hpp"

BOOST_AUTO_TEST_SUITE( Problem28 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem28::solve();
        BOOST_CHECK_EQUAL(res, 669171001);
    }

BOOST_AUTO_TEST_SUITE_END()