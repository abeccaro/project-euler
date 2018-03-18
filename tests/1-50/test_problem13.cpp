//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/13/problem13.hpp"

BOOST_AUTO_TEST_SUITE( Problem13 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem13::solve();
        std::vector<unsigned int> sol = {5, 5, 3, 7, 3, 7, 6, 2, 3, 0};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), sol.begin(), sol.end());
    }

BOOST_AUTO_TEST_SUITE_END()