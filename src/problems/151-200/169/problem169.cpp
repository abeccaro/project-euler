//
// Created by Alex Beccaro on 08/05/2023.
//

#include "problem169.hpp"


using boost::hash;
using boost::multiprecision::uint128_t;
using std::unordered_map;
using std::pair;

namespace problems {
    unordered_map<pair<uint128_t, uint128_t>, uint64_t, hash<pair<uint128_t, uint128_t>>> problem169::mem;

    uint64_t problem169::f(const uint128_t& n, const uint128_t& max_pow) {
        pair<uint128_t, uint128_t> key = {n, max_pow};
        if (mem.contains(key))
            return mem[key];

         if (4 * max_pow - 2 < n) {
            mem[key] = 0;
            return 0;
        }

        uint64_t res = 0;

        for (auto pow = max_pow; pow > 0; pow /= 2) {
            if (n == pow)
                res++;
            else if (n > pow && pow != 1)
                res += f(n - pow, pow / 2);

            if (n == 2 * pow)
                res++;
            else if (n > 2 * pow && pow != 1)
                res += f(n - 2 * pow, pow / 2);
        }

        mem[key] = res;
        return res;
    }

    uint64_t problem169::solve(const uint128_t& n) {
        uint128_t max_pow = 1;
        while (max_pow + max_pow < n)
            max_pow += max_pow;

        return f(n, max_pow);
    }
}