//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/51-100/70/problem70.hpp"

BOOST_AUTO_TEST_SUITE( Problem70 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem70::solve();
        BOOST_CHECK_EQUAL(res, 8319823);
    }

BOOST_AUTO_TEST_SUITE_END()