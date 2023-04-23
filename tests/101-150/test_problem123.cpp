//
// Created by Alex Beccaro on 22/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/123/problem123.hpp"

BOOST_AUTO_TEST_SUITE( Problem123 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem123::solve(9);
        BOOST_CHECK_EQUAL(res, 7037);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem123::solve();
        BOOST_CHECK_EQUAL(res, 21035);
    }

BOOST_AUTO_TEST_SUITE_END()