//
// Created by Alex Beccaro on 28/01/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/134/problem134.hpp"

BOOST_AUTO_TEST_SUITE( Problem134 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem134::solve();
        BOOST_CHECK_EQUAL(res, 18613426663617118);
    }

BOOST_AUTO_TEST_SUITE_END()