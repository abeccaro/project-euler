//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/19/problem19.hpp"

BOOST_AUTO_TEST_SUITE( Problem19 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem19::solve();
        BOOST_CHECK_EQUAL(res, 171);
    }

BOOST_AUTO_TEST_SUITE_END()