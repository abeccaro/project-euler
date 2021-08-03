//
// Created by Alex Beccaro on 02/08/2021.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/150/problem150.hpp"

BOOST_AUTO_TEST_SUITE( Problem150 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem150::solve();
        BOOST_CHECK_EQUAL(res, -271248680);
    }

BOOST_AUTO_TEST_SUITE_END()