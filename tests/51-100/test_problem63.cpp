//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/63/problem63.hpp"

BOOST_AUTO_TEST_SUITE( Problem63 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem63::solve();
        BOOST_CHECK_EQUAL(res, 49);
    }

BOOST_AUTO_TEST_SUITE_END()