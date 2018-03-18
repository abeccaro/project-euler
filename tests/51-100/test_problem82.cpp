//
// Created by Alex Beccaro on 25/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/82/problem82.hpp"

BOOST_AUTO_TEST_SUITE( Problem82 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem82::solve();
        BOOST_CHECK_EQUAL(res, 260324);
    }

BOOST_AUTO_TEST_SUITE_END()