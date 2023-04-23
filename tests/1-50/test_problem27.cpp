//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/27/problem27.hpp"

BOOST_AUTO_TEST_SUITE( Problem27 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem27::solve();
        BOOST_CHECK_EQUAL(res, -59231);
    }

BOOST_AUTO_TEST_SUITE_END()