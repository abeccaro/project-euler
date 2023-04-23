//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/61/problem61.hpp"

BOOST_AUTO_TEST_SUITE( Problem61 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem61::solve(3);
        BOOST_CHECK_EQUAL(res, 19291);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem61::solve();
        BOOST_CHECK_EQUAL(res, 28684);
    }

BOOST_AUTO_TEST_SUITE_END()