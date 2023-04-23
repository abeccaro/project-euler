//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/81/problem81.hpp"

BOOST_AUTO_TEST_SUITE( Problem81 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem81::solve();
        BOOST_CHECK_EQUAL(res, 427337);
    }

BOOST_AUTO_TEST_SUITE_END()