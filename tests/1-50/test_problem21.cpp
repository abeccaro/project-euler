//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/21/problem21.hpp"

BOOST_AUTO_TEST_SUITE( Problem21 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem21::solve();
        BOOST_CHECK_EQUAL(res, 31626);
    }

BOOST_AUTO_TEST_SUITE_END()