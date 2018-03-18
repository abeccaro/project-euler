//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/43/problem43.hpp"

BOOST_AUTO_TEST_SUITE( Problem43 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem43::solve();
        BOOST_CHECK_EQUAL(res, 16695334890);
    }

BOOST_AUTO_TEST_SUITE_END()