//
// Created by Alex Beccaro on 26/02/18.
//

#include "problem87.hpp"
#include <series/primes.hpp>

using series::primes;

namespace problems {
    uint problem87::solve(uint ub) {
        primes<uint> p;
        std::vector<bool> mem(ub);
        uint result = 0;

        for (uint c : p) {
            uint c2 = c * c;
            uint c4 = c2 * c2;

            if (c4 >= ub)
                break;

            for (uint b : p) {
                uint b3 = b * b * b;

                if (c4 + b3 >= ub)
                    break;

                for (uint a : p) {
                    uint a2 = a * a;
                    uint n = c4 + b3 + a2;

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