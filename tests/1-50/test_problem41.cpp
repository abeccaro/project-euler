//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/41/problem41.hpp"

BOOST_AUTO_TEST_SUITE( Problem41 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem41::solve();
        BOOST_CHECK_EQUAL(res, 7652413);
    }

BOOST_AUTO_TEST_SUITE_END()