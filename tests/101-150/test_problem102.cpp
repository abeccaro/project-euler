//
// Created by Alex Beccaro on 23/03/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/102/problem102.hpp"

BOOST_AUTO_TEST_SUITE( Problem102 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem102::solve();
        BOOST_CHECK_EQUAL(res, 228);
    }

BOOST_AUTO_TEST_SUITE_END()