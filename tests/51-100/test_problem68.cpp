//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/68/problem68.hpp"

BOOST_AUTO_TEST_SUITE( Problem68 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem68::solve();
        BOOST_CHECK_EQUAL(res.size(), 16);
        BOOST_CHECK_EQUAL(res, "6531031914842725");
    }

BOOST_AUTO_TEST_SUITE_END()