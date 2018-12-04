//
// Created by Alex Beccaro on 23/03/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/104/problem104.hpp"

BOOST_AUTO_TEST_SUITE( Problem104 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem104::solve();
        BOOST_CHECK_EQUAL(res, 329468);
    }

BOOST_AUTO_TEST_SUITE_END()