//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/11/problem11.hpp"

BOOST_AUTO_TEST_SUITE( Problem11 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem11::solve();
        BOOST_CHECK_EQUAL(res, 70600674);
    }

BOOST_AUTO_TEST_SUITE_END()