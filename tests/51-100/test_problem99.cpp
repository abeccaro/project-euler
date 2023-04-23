//
// Created by Alex Beccaro on 12/03/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/99/problem99.hpp"

BOOST_AUTO_TEST_SUITE( Problem99 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem99::solve();
        BOOST_CHECK_EQUAL(res, 709);
    }

BOOST_AUTO_TEST_SUITE_END()