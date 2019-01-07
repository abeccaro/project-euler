//
// Created by Alex Beccaro on 07/01/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/115/problem115.hpp"

BOOST_AUTO_TEST_SUITE( Problem115 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem115::solve(3);
        BOOST_CHECK_EQUAL(res, 30);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem115::solve(10);
        BOOST_CHECK_EQUAL(res, 57);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem115::solve();
        BOOST_CHECK_EQUAL(res, 168);
    }

BOOST_AUTO_TEST_SUITE_END()