//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem29.hpp"
#include <boost/unordered_set.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <generics.hpp>

using boost::unordered_set;
using boost::multiprecision::uint1024_t;
using generics::int_pow;

namespace problems {
    uint32_t problem29::solve(uint32_t max_base, uint32_t max_exp) {
        unordered_set<uint1024_t> powers;

        for (uint32_t a = 2; a <= max_base; a++)
            for (uint32_t b = 2; b <= max_exp; b++)
                powers.insert(int_pow<uint1024_t>(a, b));

        return (uint32_t) powers.size();
    }
}