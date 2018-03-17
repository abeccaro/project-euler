//
// Created by Alex Beccaro on 01/03/18.
//

#include "../../src/problems/51-100/92/problem92.hpp"

BOOST_AUTO_TEST_SUITE( Problem92 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem92::solve();
        BOOST_CHECK_EQUAL(res, 8581146);
    }

BOOST_AUTO_TEST_SUITE_END()