//
// Created by Alex Beccaro on 08/12/2019.
//

#include "problem141.hpp"
#include <cmath>
#include <numeric>
#include <vector>


using std::vector;
using std::accumulate;


namespace problems {

    uint64_t problem141::solve(uint64_t ub) {
        vector<uint64_t> solutions;
        double ub_a = cbrt(ub);

        for (uint64_t a = 2; a < ub_a; a++) {
            uint64_t a3 = a * a * a;
            for (uint64_t b = 1; b < a; b++) {
                for (uint64_t x = 1; ; x++) {
                    uint64_t n2 = b * x * (a3 * x + b);

                    if (n2 > ub)
                        break;

                    double n = sqrt(n2);
                    if (floor(n) == n) {
                        if (find(solutions.begin(), solutions.end(), n2) != solutions.end())
                            continue;

                        solutions.push_back(n2);
                    }
                }
            }
        }

        return accumulate(solutions.begin(), solutions.end(), 0ULL);
    }

}