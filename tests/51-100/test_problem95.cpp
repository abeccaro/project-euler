//
// Created by Alex Beccaro on 07/03/18.
//

#include "../../src/problems/51-100/95/problem95.hpp"

BOOST_AUTO_TEST_SUITE( Problem95 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem95::solve();
        BOOST_CHECK_EQUAL(res, 14316);
    }

BOOST_AUTO_TEST_SUITE_END()