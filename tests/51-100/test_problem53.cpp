//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/53/problem53.hpp"

BOOST_AUTO_TEST_SUITE( Problem53 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res22 = problems::problem53::solve(22);
        BOOST_CHECK_EQUAL(res22, 0);
        auto res23 = problems::problem53::solve(23);
        BOOST_CHECK_GT(res23, 0U);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem53::solve();
        BOOST_CHECK_EQUAL(res, 4075);
    }

BOOST_AUTO_TEST_SUITE_END()