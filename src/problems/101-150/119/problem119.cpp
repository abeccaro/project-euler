//
// Created by Alex Beccaro on 17/01/2019.
//

#include "problem119.hpp"
#include <numeric>
#include <generics.hpp>


using std::vector;
using std::numeric_limits;
using std::accumulate;
using std::sort;

using generics::digits;


namespace problems {

    uint64_t problem119::solve(uint32_t n) {
        // empirical bounds
        const uint32_t BASE_UB = 100;
        const uint64_t UB = numeric_limits<uint64_t>::max() / BASE_UB;

        vector<uint64_t> v;
        for (uint32_t a = 2; a < BASE_UB; a++) {
            uint64_t x = a * a;

            while (x < UB) {
                vector<uint32_t> digs = digits(x);
                int d_sum = accumulate(digs.begin(), digs.end(), 0);

                if (d_sum == a)
                    v.push_back(x);

                x *= a;
            }
        }

        sort(v.begin(), v.end());
        return v[n-1];
    }

}