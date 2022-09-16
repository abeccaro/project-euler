//
// Created by Alex Beccaro on 13/09/2022.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/151-200/158/problem158.hpp"

BOOST_AUTO_TEST_SUITE( Problem158 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem158::solve(3);
        BOOST_CHECK_EQUAL(res, 10400);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem158::solve();
        BOOST_CHECK_EQUAL(res, 409511334375);
    }

BOOST_AUTO_TEST_SUITE_END()