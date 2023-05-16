//
// Created by Alex Beccaro on 16/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/170/problem170.hpp"

BOOST_AUTO_TEST_SUITE( Problem170 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem170::solve();
        BOOST_CHECK_EQUAL(res, 9857164023);
    }

BOOST_AUTO_TEST_SUITE_END()