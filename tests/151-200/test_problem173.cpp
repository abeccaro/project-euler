//
// Created by Alex Beccaro on 21/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/173/problem173.hpp"

BOOST_AUTO_TEST_SUITE( Problem173 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem173::solve(100);
        BOOST_CHECK_EQUAL(res, 41);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem173::solve();
        BOOST_CHECK_EQUAL(res, 1572729);
    }

BOOST_AUTO_TEST_SUITE_END()