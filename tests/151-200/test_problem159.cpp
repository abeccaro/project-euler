//
// Created by Alex Beccaro on 17/09/2022.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/159/problem159.hpp"

BOOST_AUTO_TEST_SUITE( Problem159 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem159::solve();
        BOOST_CHECK_EQUAL(res, 14489159);
    }

BOOST_AUTO_TEST_SUITE_END()