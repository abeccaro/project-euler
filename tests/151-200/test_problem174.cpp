//
// Created by Alex Beccaro on 21/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/174/problem174.hpp"

BOOST_AUTO_TEST_SUITE( Problem174 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem174::solve();
        BOOST_CHECK_EQUAL(res, 209566);
    }

BOOST_AUTO_TEST_SUITE_END()