//
// Created by Alex Beccaro on 05/12/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/108/problem108.hpp"

BOOST_AUTO_TEST_SUITE( Problem108 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem108::solve();
        BOOST_CHECK_EQUAL(res, 180180);
    }

BOOST_AUTO_TEST_SUITE_END()