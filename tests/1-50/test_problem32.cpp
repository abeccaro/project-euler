//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/32/problem32.hpp"

BOOST_AUTO_TEST_SUITE( Problem32 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem32::solve();
        BOOST_CHECK_EQUAL(res, 45228);
    }

BOOST_AUTO_TEST_SUITE_END()