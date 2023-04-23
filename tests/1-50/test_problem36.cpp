//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/36/problem36.hpp"

BOOST_AUTO_TEST_SUITE( Problem36 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem36::solve();
        BOOST_CHECK_EQUAL(res, 872187);
    }

BOOST_AUTO_TEST_SUITE_END()