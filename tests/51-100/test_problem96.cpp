//
// Created by Alex Beccaro on 12/03/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/96/problem96.hpp"

BOOST_AUTO_TEST_SUITE( Problem96 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem96::solve();
        BOOST_CHECK_EQUAL(res, 24702);
    }

BOOST_AUTO_TEST_SUITE_END()