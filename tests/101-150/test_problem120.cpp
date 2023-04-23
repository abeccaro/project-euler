//
// Created by Alex Beccaro on 19/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/120/problem120.hpp"

BOOST_AUTO_TEST_SUITE( Problem120 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem120::solve();
        BOOST_CHECK_EQUAL(res, 333082500);
    }

BOOST_AUTO_TEST_SUITE_END()