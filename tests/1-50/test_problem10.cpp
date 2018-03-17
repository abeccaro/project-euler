//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/10/problem10.hpp"

BOOST_AUTO_TEST_SUITE( Problem10 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem10::solve(10);
        BOOST_CHECK_EQUAL(res, 17);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem10::solve();
        BOOST_CHECK_EQUAL(res, 142913828922);
    }

BOOST_AUTO_TEST_SUITE_END()