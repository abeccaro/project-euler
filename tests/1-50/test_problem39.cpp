//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/39/problem39.hpp"

BOOST_AUTO_TEST_SUITE( Problem39 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem39::solve();
        BOOST_CHECK_EQUAL(res, 840);
    }

BOOST_AUTO_TEST_SUITE_END()