//
// Created by Alex Beccaro on 02/08/2021.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/149/problem149.hpp"

BOOST_AUTO_TEST_SUITE( Problem149 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem149::solve();
        BOOST_CHECK_EQUAL(res, 52852124);
    }

BOOST_AUTO_TEST_SUITE_END()