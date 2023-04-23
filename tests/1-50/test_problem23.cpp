//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/23/problem23.hpp"

BOOST_AUTO_TEST_SUITE( Problem23 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem23::solve();
        BOOST_CHECK_EQUAL(res, 4179871);
    }

BOOST_AUTO_TEST_SUITE_END()