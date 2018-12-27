//
// Created by Alex Beccaro on 05/12/18.
//

#include "problem108.hpp"

using series::primes;
using prime_it = primes<uint32_t>::iterator;

namespace problems {
    uint32_t problem108::find_num(uint32_t solutions, uint32_t best, const prime_it& p, uint32_t max_mult_p,
            uint32_t n, uint32_t sol_found) {
        if (n > best)
            return best;

        if (sol_found > solutions) {
            best = n;
            return best;
        }

        for (uint32_t i = 1; i <= max_mult_p && n < best; i++) {
            n *= *p;
            uint32_t new_solutions = sol_found * (i * 2 + 1);

            uint32_t rec_best = find_num(solutions, best, p + 1, i, n, new_solutions);

            if (rec_best < best)
                best = rec_best;
        }

        return best;
    }

    uint64_t problem108::solve(uint32_t n) {
        primes<uint32_t> ps;
        uint32_t best = std::numeric_limits<uint32_t>::max();

        return find_num(2 * n, best, ps.begin(), n, 1, 1);
    }
}