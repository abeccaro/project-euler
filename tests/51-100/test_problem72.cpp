//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/51-100/72/problem72.hpp"

BOOST_AUTO_TEST_SUITE( Problem72 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem72::solve(8);
        BOOST_CHECK_EQUAL(res, 21);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem72::solve();
        BOOST_CHECK_EQUAL(res, 303963552391);
    }

BOOST_AUTO_TEST_SUITE_END()