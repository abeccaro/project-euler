//
// Created by Alex Beccaro on 29/01/18.
//

#include "../../src/problems/51-100/85/problem85.hpp"

BOOST_AUTO_TEST_SUITE( Problem85 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem85::solve();
        BOOST_CHECK_EQUAL(res, 2772);
    }

BOOST_AUTO_TEST_SUITE_END()