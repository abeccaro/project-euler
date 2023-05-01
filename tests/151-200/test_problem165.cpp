//
// Created by Alex Beccaro on 29/04/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/165/problem165.hpp"

BOOST_AUTO_TEST_SUITE( Problem165 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem165::solve();
        BOOST_CHECK_EQUAL(res, 2868868);
    }

BOOST_AUTO_TEST_SUITE_END()