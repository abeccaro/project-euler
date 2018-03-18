//
// Created by Alex Beccaro on 26/02/18.
//

#include "problem87.hpp"
#include <series/primes.hpp>

using std::vector;
using series::primes;

namespace problems {
    uint32_t problem87::solve(uint32_t ub) {
        primes<uint32_t> p;
        vector<bool> mem(ub);
        uint32_t result = 0;

        for (uint32_t c : p) {
            uint32_t c2 = c * c;
            uint32_t c4 = c2 * c2;

            if (c4 >= ub)
                break;

            for (uint32_t b : p) {
                uint32_t b3 = b * b * b;

                if (c4 + b3 >= ub)
                    break;

                for (uint32_t a : p) {
                    uint32_t a2 = a * a;
                    uint32_t n = c4 + b3 + a2;

                    if (n < ub) {
                        if (!mem[n]) {
                            mem[n] = true;
                            result++;
                        }
                    }
                    else
                        break;
                }
            }
        }

        return result;
    }
}