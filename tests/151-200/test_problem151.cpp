//
// Created by Alex Beccaro on 03/08/2021.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/151/problem151.hpp"
#include "cmath"

BOOST_AUTO_TEST_SUITE( Problem151 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = round(1000000 * problems::problem151::solve()) / 1000000;
        BOOST_CHECK_EQUAL(res, 0.464399);
    }

BOOST_AUTO_TEST_SUITE_END()