//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem77.hpp"
#include "series/primes.hpp"

using std::vector;
using series::primes;

namespace problems {
    uint32_t problem77::primes_combination(uint32_t n, const vector<uint32_t>::reverse_iterator& prime) {
        uint32_t p = *prime;

        if (p == 2)
            return n % 2 == 0 ? 1 : 0;

        if (n < p)
            return primes_combination(n, prime + 1);

        uint32_t count = primes_combination(n, prime + 1); // recursion for not using p in the sum
        count += primes_combination(n - p, prime); // recursion for using p in the sum

        return count;
    }

    uint32_t problem77::solve(uint32_t n) {
        primes<uint32_t> p; // primes lazy generator
        auto next = p.begin(); // next prime to add to ps
        vector<uint32_t> ps; // list of primes < i

        for (uint32_t i = 3; ; i++) {
            if (*next < i) { // keep ps updated
                ps.push_back(*next);
                next++;
            }
            if (primes_combination(i, ps.rbegin()) > n)
                return i;
        }
    }
}