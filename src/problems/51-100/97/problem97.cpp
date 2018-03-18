//
// Created by Alex Beccaro on 13/03/18.
//

#include "problem97.hpp"
#include <generics.hpp>

using std::string;
using boost::multiprecision::uint128_t;
using generics::mod_pow;

namespace problems {
    string problem97::solve() {
        uint128_t n = mod_pow<uint128_t>(2, 7830457, 10000000000) * 28433 + 1;

        string s = (n % 10000000000).str();
        if (s.size() < 10)
            s = string(10 - s.size(), '0').append(s);
        return s;
    }
}