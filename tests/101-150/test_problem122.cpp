//
// Created by Alex Beccaro on 21/01/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/122/problem122.hpp"

BOOST_AUTO_TEST_SUITE( Problem122 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem122::solve();
        BOOST_CHECK_EQUAL(res, 1582);
    }

BOOST_AUTO_TEST_SUITE_END()