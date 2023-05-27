//
// Created by Alex Beccaro on 22/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/175/problem175.hpp"

BOOST_AUTO_TEST_SUITE( Problem175 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem175::solve(13, 17);
        BOOST_CHECK_EQUAL(res, "4,3,1");
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem175::solve();
        BOOST_CHECK_EQUAL(res, "1,13717420,8");
    }

BOOST_AUTO_TEST_SUITE_END()