//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/37/problem37.hpp"

BOOST_AUTO_TEST_SUITE( Problem37 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem37::solve();
        BOOST_CHECK_EQUAL(res, 748317);
    }

BOOST_AUTO_TEST_SUITE_END()