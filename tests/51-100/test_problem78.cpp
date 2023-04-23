//
// Created by Alex Beccaro on 18/01/18.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/51-100/78/problem78.hpp"

BOOST_AUTO_TEST_SUITE( Problem78 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem78::solve(7);
        BOOST_CHECK_EQUAL(res, 5);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem78::solve();
        BOOST_CHECK_EQUAL(res, 55374);
    }

BOOST_AUTO_TEST_SUITE_END()