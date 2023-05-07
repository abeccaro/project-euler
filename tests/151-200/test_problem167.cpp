//
// Created by Alex Beccaro on 02/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/167/problem167.hpp"

BOOST_AUTO_TEST_SUITE( Problem167 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem167::solve();
        BOOST_CHECK_EQUAL(res, 3916160068885);
    }

BOOST_AUTO_TEST_SUITE_END()