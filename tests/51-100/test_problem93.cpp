//
// Created by Alex Beccaro on 01/03/18.
//

#include "../../src/problems/51-100/93/problem93.hpp"

BOOST_AUTO_TEST_SUITE( Problem93 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem93::solve();
        BOOST_CHECK_EQUAL(res, "1258");
    }

BOOST_AUTO_TEST_SUITE_END()