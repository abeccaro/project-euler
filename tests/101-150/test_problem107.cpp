//
// Created by Alex Beccaro on 05/12/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/107/problem107.hpp"

BOOST_AUTO_TEST_SUITE( Problem107 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem107::solve();
        BOOST_CHECK_EQUAL(res, 259679);
    }

BOOST_AUTO_TEST_SUITE_END()