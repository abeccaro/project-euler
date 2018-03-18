//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/54/problem54.hpp"

BOOST_AUTO_TEST_SUITE( Problem54 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem54::solve();
        BOOST_CHECK_EQUAL(res, 376);
    }

BOOST_AUTO_TEST_SUITE_END()