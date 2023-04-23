//
// Created by Alex Beccaro on 06/12/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/110/problem110.hpp"

BOOST_AUTO_TEST_SUITE( Problem110 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem110::solve(100);
        BOOST_CHECK_EQUAL(res, 1260);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem110::solve();
        BOOST_CHECK_EQUAL(res, 9350130049860600);
    }

BOOST_AUTO_TEST_SUITE_END()