//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/1-50/46/problem46.hpp"

BOOST_AUTO_TEST_SUITE( Problem46 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem46::solve();
        BOOST_CHECK_EQUAL(res, 5777);
    }

BOOST_AUTO_TEST_SUITE_END()