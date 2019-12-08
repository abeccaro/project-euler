//
// Created by Alex Beccaro on 08/12/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/139/problem139.hpp"

BOOST_AUTO_TEST_SUITE( Problem139 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem139::solve();
        BOOST_CHECK_EQUAL(res, 10057761);
    }

BOOST_AUTO_TEST_SUITE_END()