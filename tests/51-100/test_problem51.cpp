//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/51/problem51.hpp"

BOOST_AUTO_TEST_SUITE( Problem51 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem51::solve();
        BOOST_CHECK_EQUAL(res, 121313);
    }

BOOST_AUTO_TEST_SUITE_END()