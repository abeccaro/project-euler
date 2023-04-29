//
// Created by Alex Beccaro on 29/04/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/164/problem164.hpp"

BOOST_AUTO_TEST_SUITE( Problem164 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem164::solve();
        BOOST_CHECK_EQUAL(res, 378158756814587);
    }

BOOST_AUTO_TEST_SUITE_END()