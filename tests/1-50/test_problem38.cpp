//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/38/problem38.hpp"

BOOST_AUTO_TEST_SUITE( Problem38 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem38::solve();
        BOOST_CHECK_EQUAL(res, 932718654);
    }

BOOST_AUTO_TEST_SUITE_END()