//
// Created by Alex Beccaro on 05/01/18.
//

#include "problem39.hpp"
#include <vector>
#include <cmath>

using std::vector;

namespace problems {
    uint problem39::solve(uint ub) {
        const uint A_BOUND = ub / 3;

        vector<uint> counts(ub - 2); // no possible triangles for 0, 1 and 2.

        for (uint a = 1; a <= A_BOUND; a++) {
            uint B_BOUND = (ub - a) / 2;
            for (uint b = a; b <= B_BOUND; b++) {
                uint c_squared = a * a + b * b;
                auto c = (uint) sqrt(c_squared);
                if (c * c == c_squared) { // if it is right angle triangle
                    uint p = a + b + c;

                    if (p <= 1000)
                        counts[p - 3]++;
                }
            }
        }

        auto result = (uint) distance(counts.begin(), max_element(counts.begin(), counts.end())) + 3;
        return result;
    }
}