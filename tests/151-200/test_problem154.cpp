//
// Created by Alex Beccaro on 02/09/2022.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/151-200/154/problem154.hpp"

BOOST_AUTO_TEST_SUITE( Problem154 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem154::solve();
        BOOST_CHECK_EQUAL(res, 479742450);
    }

BOOST_AUTO_TEST_SUITE_END()