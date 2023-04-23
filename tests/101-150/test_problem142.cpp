//
// Created by Alex Beccaro on 17/12/2019.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/101-150/142/problem142.hpp"

BOOST_AUTO_TEST_SUITE( Problem142 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem142::solve();
        BOOST_CHECK_EQUAL(res, 1006193);
    }

BOOST_AUTO_TEST_SUITE_END()