//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/51-100/56/problem56.hpp"

BOOST_AUTO_TEST_SUITE( Problem56 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem56::solve();
        BOOST_CHECK_EQUAL(res, 972);
    }

BOOST_AUTO_TEST_SUITE_END()