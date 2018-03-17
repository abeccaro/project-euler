//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/22/problem22.hpp"

BOOST_AUTO_TEST_SUITE( Problem22 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem22::solve();
        BOOST_CHECK_EQUAL(res, 871198282);
    }

BOOST_AUTO_TEST_SUITE_END()