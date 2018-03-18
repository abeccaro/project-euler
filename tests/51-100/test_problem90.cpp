//
// Created by Alex Beccaro on 28/02/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/90/problem90.hpp"

BOOST_AUTO_TEST_SUITE( Problem90 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem90::solve();
        BOOST_CHECK_EQUAL(res, 1217);
    }

BOOST_AUTO_TEST_SUITE_END()