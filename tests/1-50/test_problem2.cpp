//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/2/problem2.hpp"

BOOST_AUTO_TEST_SUITE( Problem2 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem2::solve();
        BOOST_CHECK_EQUAL(res, 4613732);
    }

BOOST_AUTO_TEST_SUITE_END()