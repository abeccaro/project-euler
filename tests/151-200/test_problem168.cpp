//
// Created by Alex Beccaro on 07/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/168/problem168.hpp"

BOOST_AUTO_TEST_SUITE( Problem168 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem168::solve();
        BOOST_CHECK_EQUAL(res, 59206);
    }

BOOST_AUTO_TEST_SUITE_END()