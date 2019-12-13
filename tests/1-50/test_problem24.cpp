//
// Created by Alex Beccaro on 18/01/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/1-50/24/problem24.hpp"

BOOST_AUTO_TEST_SUITE( Problem24 )

    BOOST_AUTO_TEST_CASE( Example ) {
        std::vector<uint32_t> base = {0,1,2};
        std::vector<uint32_t> sol = base;
        for (uint32_t i = 1; i <= 6; i++) {
            std::vector<uint32_t> res = problems::problem24::solve(base, i);
            BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),sol.begin(), sol.end());
            next_permutation(sol.begin(), sol.end());
        }
    }

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem24::solve();
        std::vector<uint32_t> sol = {2,7,8,3,9,1,5,4,6,0};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), sol.begin(), sol.end());
    }

BOOST_AUTO_TEST_SUITE_END()