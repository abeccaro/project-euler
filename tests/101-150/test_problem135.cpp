//
// Created by Alex Beccaro on 05/12/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/135/problem135.hpp"

BOOST_AUTO_TEST_SUITE( Problem135 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem135::solve();
        BOOST_CHECK_EQUAL(res, 4989);
    }

BOOST_AUTO_TEST_SUITE_END()