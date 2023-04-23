//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/73/problem73.hpp"

BOOST_AUTO_TEST_SUITE( Problem73 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem73::solve(8);
        BOOST_CHECK_EQUAL(res, 3);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem73::solve();
        BOOST_CHECK_EQUAL(res, 7295372);
    }

BOOST_AUTO_TEST_SUITE_END()