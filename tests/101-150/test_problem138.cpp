//
// Created by Alex Beccaro on 06/12/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/138/problem138.hpp"

BOOST_AUTO_TEST_SUITE( Problem138 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem138::solve(2);
        BOOST_CHECK_EQUAL(res, 322);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem138::solve();
        BOOST_CHECK_EQUAL(res, 1118049290473932);
    }

BOOST_AUTO_TEST_SUITE_END()