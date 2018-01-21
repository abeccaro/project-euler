//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem29.hpp"
#include <boost/unordered_set.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using boost::unordered_set;
using boost::multiprecision::uint1024_t;

namespace problems {
    uint problem29::solve(uint max_base, uint max_exp) {
        unordered_set<uint1024_t> powers;

        for (uint a = 2; a <= max_base; a++)
            for (uint b = 2; b <= max_exp; b++)
                powers.insert((uint1024_t) pow(a, b));

        return (uint) powers.size();
    }
}