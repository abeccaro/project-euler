//
// Created by Alex Beccaro on 21/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/172/problem172.hpp"

BOOST_AUTO_TEST_SUITE( Problem172 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem172::solve();
        BOOST_CHECK_EQUAL(res, 227485267000992000);
    }

BOOST_AUTO_TEST_SUITE_END()