//
// Created by Alex Beccaro on 23/03/18.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/problems/101-150/103/problem103.hpp"

BOOST_AUTO_TEST_SUITE( Problem103 )

    BOOST_AUTO_TEST_CASE( Solution ) {
        auto res = problems::problem103::solve(7);
        std::vector<uint32_t> sol = {20, 31, 38, 39, 40, 42, 45};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), sol.begin(), sol.end());
    }

BOOST_AUTO_TEST_SUITE_END()