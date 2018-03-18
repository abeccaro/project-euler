//
// Created by Alex Beccaro on 25/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/83/problem83.hpp"

BOOST_AUTO_TEST_SUITE( Problem83 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem83::solve();
        BOOST_CHECK_EQUAL(res, 425185);
    }

BOOST_AUTO_TEST_SUITE_END()