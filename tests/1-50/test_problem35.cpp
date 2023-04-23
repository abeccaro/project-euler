//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/35/problem35.hpp"

BOOST_AUTO_TEST_SUITE( Problem35 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem35::solve(100);
        BOOST_CHECK_EQUAL(res, 13);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem35::solve();
        BOOST_CHECK_EQUAL(res, 55);
    }

BOOST_AUTO_TEST_SUITE_END()