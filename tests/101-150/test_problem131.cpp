//
// Created by Alex Beccaro on 24/01/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/131/problem131.hpp"

BOOST_AUTO_TEST_SUITE( Problem131 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem131::solve(100);
        BOOST_CHECK_EQUAL(res, 4);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem131::solve();
        BOOST_CHECK_EQUAL(res, 173);
    }

BOOST_AUTO_TEST_SUITE_END()