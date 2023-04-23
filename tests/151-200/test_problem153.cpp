//
// Created by Alex Beccaro on 27/08/2022.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/153/problem153.hpp"

BOOST_AUTO_TEST_SUITE( Problem153 )

    BOOST_AUTO_TEST_CASE( Example1 ) {
        auto res = problems::problem153::solve(5);
        BOOST_CHECK_EQUAL(res, 35);
    }

    BOOST_AUTO_TEST_CASE( Example2 ) {
        auto res = problems::problem153::solve(100000);
        BOOST_CHECK_EQUAL(res, 17924657155);
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem153::solve();
        BOOST_CHECK_EQUAL(res, 17971254122360635);
    }

BOOST_AUTO_TEST_SUITE_END()