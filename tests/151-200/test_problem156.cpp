//
// Created by Alex Beccaro on 12/09/2022.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/151-200/156/problem156.hpp"

BOOST_AUTO_TEST_SUITE( Problem156 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem156::solve();
        BOOST_CHECK_EQUAL(res, 21295121502550);
    }

BOOST_AUTO_TEST_SUITE_END()