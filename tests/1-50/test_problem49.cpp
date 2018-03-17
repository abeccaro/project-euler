//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/49/problem49.hpp"

BOOST_AUTO_TEST_SUITE( Problem49 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem49::solve();
        BOOST_CHECK_EQUAL(res, 296962999629);
    }

BOOST_AUTO_TEST_SUITE_END()