//
// Created by Alex Beccaro on 17/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/171/problem171.hpp"

BOOST_AUTO_TEST_SUITE( Problem171 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem171::solve();
        BOOST_CHECK_EQUAL(res, 142989277);
    }

BOOST_AUTO_TEST_SUITE_END()