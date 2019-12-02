//
// Created by Alex Beccaro on 25/01/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/133/problem133.hpp"

BOOST_AUTO_TEST_SUITE( Problem133 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem133::solve(100);
        BOOST_CHECK_EQUAL(res, 142);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem133::solve();
        BOOST_CHECK_EQUAL(res, 453647705);
    }

BOOST_AUTO_TEST_SUITE_END()