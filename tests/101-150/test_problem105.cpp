//
// Created by Alex Beccaro on 03/12/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/105/problem105.hpp"

BOOST_AUTO_TEST_SUITE( Problem105 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem105::solve();
        BOOST_CHECK_EQUAL(res, 73702);
    }

BOOST_AUTO_TEST_SUITE_END()