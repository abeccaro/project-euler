//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/44/problem44.hpp"

BOOST_AUTO_TEST_SUITE( Problem44 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem44::solve();
        BOOST_CHECK_EQUAL(res, 5482660);
    }

BOOST_AUTO_TEST_SUITE_END()