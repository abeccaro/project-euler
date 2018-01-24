//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem77.hpp"
#include <series/primes.hpp>

using std::vector;
using series::primes;

namespace problems {
    uint problem77::primes_combination(uint n, const rev_it &prime) {
        uint p = *prime;

        if (p == 2)
            return n % 2 == 0 ? 1 : 0;

        if (n < p)
            return primes_combination(n, prime + 1);

        uint count = primes_combination(n, prime + 1); // recursion for not using p in the sum
        count += primes_combination(n - p, prime); // recursion for using p in the sum

        return count;
    }

    uint problem77::solve(uint n) {
        primes<uint> p; // primes lazy generator
        auto next = p.begin(); // next prime to add to ps
        vector<uint> ps; // list of primes < i

        for (uint i = 3; ; i++) {
            if (*next < i) { // keep ps updated
                ps.push_back(*next);
                next++;
            }
            if (primes_combination(i, ps.rbegin()) > n)
                return i;
        }
    }
}