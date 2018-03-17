//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/31/problem31.hpp"

BOOST_AUTO_TEST_SUITE( Problem31 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem31::solve();
        BOOST_CHECK_EQUAL(res, 73682);
    }

BOOST_AUTO_TEST_SUITE_END()