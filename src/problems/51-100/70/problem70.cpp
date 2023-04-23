//
// Created by Alex Beccaro on 21/01/18.
//

#include "problem70.hpp"
#include "generics.hpp"
#include "series/primes.hpp"

using std::vector;

using generics::digits;

namespace problems {
    uint32_t problem70::solve(uint32_t ub) {
        double min = std::numeric_limits<double>::max();
        uint32_t result = 0;
        series::primes<uint64_t> ps;

        // Can't be prime as ϕ(p) = p-1 and p/p-1 can't be a p permutation.
        // Next best candidates are semiprimes (numbers that only have 2 prime divisors).
        for (auto p = ps.begin() + 1; p != ps.end(); p++) {
            for (auto q = ps.begin(); q != p; q++) {
                if (*p > ub)
                    return result;

                uint32_t n = *p * *q;
                if (n > ub)
                    break;

                uint32_t t = (*p - 1) * (*q - 1); // totient
                double x = (double) n / t;

                if (x < min) {
                    vector<uint32_t> digs_t = digits(t);
                    vector<uint32_t> digs_n = digits(n);
                    sort(digs_t.begin(), digs_t.end());
                    sort(digs_n.begin(), digs_n.end());

                    if (digs_t == digs_n) {
                        min = x;
                        result = n;
                    }
                }
            }
        }

        return 0;
    }
}
