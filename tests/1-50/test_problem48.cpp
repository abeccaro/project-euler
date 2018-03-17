//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/1-50/48/problem48.hpp"

BOOST_AUTO_TEST_SUITE( Problem48 )

    BOOST_AUTO_TEST_CASE( Example ) {
        auto res = problems::problem48::solve(10);
        vector<uint> sol = {0, 4, 0, 5, 0, 7, 1, 3, 1, 7};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), sol.begin(), sol.end());
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem48::solve();
        vector<uint> sol = {9, 1, 1, 0, 8, 4, 6, 7, 0, 0};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), sol.begin(), sol.end());
    }

BOOST_AUTO_TEST_SUITE_END()