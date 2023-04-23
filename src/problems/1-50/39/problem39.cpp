//
// Created by Alex Beccaro on 05/01/18.
//

#include "problem39.hpp"
#include "vector"
#include "cmath"
#include "algorithm"

using std::vector;
using std::max_element;

namespace problems {
    uint32_t problem39::solve(uint32_t ub) {
        const uint32_t a_bound = ub / 3;

        vector<uint32_t> counts(ub - 2); // no possible triangles for 0, 1 and 2.

        for (uint32_t a = 1; a <= a_bound; a++) {
            uint32_t b_bound = (ub - a) / 2;
            for (uint32_t b = a; b <= b_bound; b++) {
                uint32_t c_squared = a * a + b * b;
                auto c = (uint32_t) sqrt(c_squared);
                if (c * c == c_squared) { // if it is right angle triangle
                    uint32_t p = a + b + c;

                    if (p <= ub)
                        counts[p - 3]++;
                }
            }
        }

        return (uint32_t) distance(counts.begin(), max_element(counts.begin(), counts.end())) + 3;
    }
}