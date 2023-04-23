//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/40/problem40.hpp"

BOOST_AUTO_TEST_SUITE( Problem40 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem40::solve();
        BOOST_CHECK_EQUAL(res, 210);
    }

BOOST_AUTO_TEST_SUITE_END()