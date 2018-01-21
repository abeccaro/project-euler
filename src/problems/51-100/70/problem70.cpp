//
// Created by Alex Beccaro on 21/01/18.
//

#include "problem70.hpp"
#include <generics.hpp>
#include <series/primes.hpp>

using std::sort;
using generics::digits;
using series::primes;

namespace problems {
    uint problem70::solve(uint ub) {
        double min = std::numeric_limits<double>::max();
        uint result = 0;
        primes<ulong> ps;

        // Can't be prime as ϕ(p) = p-1 and p/p-1 can't be a p permutation.
        // Next best candidates are semiprimes (numbers that only have 2 prime divisors).
        for (auto p = ps.begin() + 1; p != ps.end(); p++)
            for (auto q = ps.begin(); q != p; q++) {
                if (*p > ub)
                    return result;

                uint n = *p * *q;
                if (n > ub)
                    break;

                uint t = (*p - 1) * (*q - 1); // totient
                double x = (double) n / t;

                if (x < min) {
                    vector<uint> digs_t = digits(t);
                    vector<uint> digs_n = digits(n);
                    sort(digs_t.begin(), digs_t.end());
                    sort(digs_n.begin(), digs_n.end());

                    if (digs_t == digs_n) {
                        min = x;
                        result = n;
                    }
                }
            }
    }
}
