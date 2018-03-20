//
// Created by Alex Beccaro on 12/03/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/98/problem98.hpp"

BOOST_AUTO_TEST_SUITE( Problem98 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem98::solve();
        BOOST_CHECK_EQUAL(res, 18769);
    }

BOOST_AUTO_TEST_SUITE_END()