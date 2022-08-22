//
// Created by Alex Beccaro on 17/08/2022.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/151-200/152/problem152.hpp"

BOOST_AUTO_TEST_SUITE( Problem152 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem152::solve(45);
        BOOST_CHECK_EQUAL(res, 3);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem152::solve();
        BOOST_CHECK_EQUAL(res, 301);
    }

BOOST_AUTO_TEST_SUITE_END()