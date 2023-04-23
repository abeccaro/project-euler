//
// Created by Alex Beccaro on 16/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/118/problem118.hpp"

BOOST_AUTO_TEST_SUITE( Problem118 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem118::solve();
        BOOST_CHECK_EQUAL(res, 44680);
    }

BOOST_AUTO_TEST_SUITE_END()