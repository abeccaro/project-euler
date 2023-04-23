//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/59/problem59.hpp"

BOOST_AUTO_TEST_SUITE( Problem59 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem59::solve();
        BOOST_CHECK_EQUAL(res, 107359);
    }

BOOST_AUTO_TEST_SUITE_END()