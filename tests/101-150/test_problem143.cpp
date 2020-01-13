//
// Created by Alex Beccaro on 17/12/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/143/problem143.hpp"

BOOST_AUTO_TEST_SUITE( Problem143 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem143::solve();
        BOOST_CHECK_EQUAL(res, 30758397);
    }

BOOST_AUTO_TEST_SUITE_END()