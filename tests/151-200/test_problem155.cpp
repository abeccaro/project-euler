//
// Created by Alex Beccaro on 04/09/2022.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/151-200/155/problem155.hpp"

BOOST_AUTO_TEST_SUITE( Problem155 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem155::solve();
        BOOST_CHECK_EQUAL(res, 3857447);
    }

BOOST_AUTO_TEST_SUITE_END()