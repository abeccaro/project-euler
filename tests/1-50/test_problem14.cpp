//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/14/problem14.hpp"

BOOST_AUTO_TEST_SUITE( Problem14 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem14::solve();
        BOOST_CHECK_EQUAL(res, 837799);
    }

BOOST_AUTO_TEST_SUITE_END()