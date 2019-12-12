//
// Created by Alex Beccaro on 09/12/2019.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/140/problem140.hpp"

BOOST_AUTO_TEST_SUITE( Problem140 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem140::solve(20) - problems::problem140::solve(19);
        BOOST_CHECK_EQUAL(res, 211345365);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem140::solve();
        BOOST_CHECK_EQUAL(res, 5673835352990);
    }

BOOST_AUTO_TEST_SUITE_END()