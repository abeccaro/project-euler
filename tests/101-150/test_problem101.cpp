//
// Created by Alex Beccaro on 21/03/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/101/problem101.hpp"

BOOST_AUTO_TEST_SUITE( Problem101 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem101::solve([](int32_t x) { return x * x * x; });
        BOOST_CHECK_EQUAL(res, 74);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem101::solve();
        BOOST_CHECK_EQUAL(res, 37076114526);
    }

BOOST_AUTO_TEST_SUITE_END()