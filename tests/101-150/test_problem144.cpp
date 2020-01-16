//
// Created by Alex Beccaro on 15/01/2020.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/144/problem144.hpp"

BOOST_AUTO_TEST_SUITE( Problem144 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem144::solve();
        BOOST_CHECK_EQUAL(res, 354);
    }

BOOST_AUTO_TEST_SUITE_END()