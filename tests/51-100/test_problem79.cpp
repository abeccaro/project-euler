//
// Created by Alex Beccaro on 18/01/18.
//

#include "../../src/problems/51-100/79/problem79.hpp"

BOOST_AUTO_TEST_SUITE( Problem79 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem79::solve();
        vector<uint> sol = {7, 3, 1, 6, 2, 8, 9, 0};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), sol.begin(), sol.end());
    }

BOOST_AUTO_TEST_SUITE_END()