//
// Created by Alex Beccaro on 01/05/2023.
//

#include "boost/test/unit_test.hpp"
#include "../../src/problems/151-200/166/problem166.hpp"

BOOST_AUTO_TEST_SUITE( Problem166 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem166::solve();
        BOOST_CHECK_EQUAL(res, 7130034);
    }

BOOST_AUTO_TEST_SUITE_END()