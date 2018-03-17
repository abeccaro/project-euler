//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/51-100/58/problem58.hpp"

BOOST_AUTO_TEST_SUITE( Problem58 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem58::solve();
        BOOST_CHECK_EQUAL(res, 26241);
    }

BOOST_AUTO_TEST_SUITE_END()