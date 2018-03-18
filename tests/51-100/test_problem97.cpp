//
// Created by Alex Beccaro on 12/03/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/97/problem97.hpp"

BOOST_AUTO_TEST_SUITE( Problem97 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem97::solve();
        BOOST_CHECK_EQUAL(res, "8739992577");
    }

BOOST_AUTO_TEST_SUITE_END()