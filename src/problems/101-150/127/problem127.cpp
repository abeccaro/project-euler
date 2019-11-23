//
// Created by Alex Beccaro on 23/01/2019.
//

#include "problem127.hpp"
#include <generics.hpp>


using std::vector;
using std::sort;

using primes::prime_factors;
using generics::gcd;
using rad_pair = std::pair<uint64_t, uint64_t>;


namespace problems {

    uint64_t problem127::solve(uint32_t ub) {
        uint64_t res = 0;
        std::vector<uint64_t> rads({0, 1}); // n -> rad(n)
        std::vector<rad_pair> sorted_rads({{1, 1}}); // rad(n) -> n sorted by rad(n)

        // calculate rads
        for (uint64_t i = 2; i <= ub; i++) {
            uint64_t ri = 1;
            for (const auto& f : prime_factors(i))
                ri *= f;

            rads.push_back(ri);
            sorted_rads.push_back({i, ri});
        }

        // sort them
        sort(sorted_rads.begin(), sorted_rads.end(), [](const rad_pair& p1, const rad_pair& p2){
            if (p1.second == p2.second)
                return p1.first < p2.first;
            return p1.second < p2.second;
        });

        for (uint64_t c = 3; c < ub; c++) {
            // from rad(a) * rad(b) * rad(c) < c
            // get rad(a) * rad(b) < c / rad(c)
            uint64_t m = c / rads[c];

            // if c is even its rad is a multiple of 2 and so rad(b) >= 3 and so rad(a) < m/3
            // else rad(b) >=2 and so rad(a) < m/2
            uint64_t bound = c % 2 == 0 ? m / 3 : m / 2;

            // loop on rad(a)
            for (auto it = sorted_rads.begin(); it != sorted_rads.end() && (*it).second <= bound; it++) {
                uint64_t a = (*it).first;
                if (c < a) // avoid underflow
                    continue;
                uint64_t b = c - a;

                if (a < b && rads[a] * rads[b] < m && gcd(rads[a], rads[b]) == 1) // check if hit
                    res += c;
            }
        }

        return res;
    }

}