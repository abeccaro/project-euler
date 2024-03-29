//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/67/problem67.hpp"

BOOST_AUTO_TEST_SUITE( Problem67 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem67::solve();
        BOOST_CHECK_EQUAL(res, 7273);
    }

BOOST_AUTO_TEST_SUITE_END()