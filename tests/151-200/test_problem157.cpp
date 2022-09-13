//
// Created by Alex Beccaro on 13/09/2022.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/151-200/157/problem157.hpp"

BOOST_AUTO_TEST_SUITE( Problem157 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem157::solve(1);
        BOOST_CHECK_EQUAL(res, 20);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem157::solve();
        BOOST_CHECK_EQUAL(res, 53490);
    }

BOOST_AUTO_TEST_SUITE_END()