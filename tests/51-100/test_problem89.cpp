//
// Created by Alex Beccaro on 28/02/18.
//

#include "../../src/problems/51-100/89/problem89.hpp"

BOOST_AUTO_TEST_SUITE( Problem89 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem89::solve();
        BOOST_CHECK_EQUAL(res, 743);
    }

BOOST_AUTO_TEST_SUITE_END()