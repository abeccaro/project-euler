//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/33/problem33.hpp"

BOOST_AUTO_TEST_SUITE( Problem33 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem33::solve();
        BOOST_CHECK_EQUAL(res, 100);
    }

BOOST_AUTO_TEST_SUITE_END()