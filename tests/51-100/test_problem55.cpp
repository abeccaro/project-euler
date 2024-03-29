//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/55/problem55.hpp"

BOOST_AUTO_TEST_SUITE( Problem55 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem55::solve();
        BOOST_CHECK_EQUAL(res, 249);
    }

BOOST_AUTO_TEST_SUITE_END()