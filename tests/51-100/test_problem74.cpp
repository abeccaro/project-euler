//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/74/problem74.hpp"

BOOST_AUTO_TEST_SUITE( Problem74 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem74::solve();
        BOOST_CHECK_EQUAL(res, 402);
    }

BOOST_AUTO_TEST_SUITE_END()