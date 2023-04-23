//
// Created by Alex Beccaro on 02/03/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/94/problem94.hpp"

BOOST_AUTO_TEST_SUITE( Problem94 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem94::solve();
        BOOST_CHECK_EQUAL(res, 518408346);
    }

BOOST_AUTO_TEST_SUITE_END()