//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem49.hpp"
#include <series/primes.hpp>
#include <generics.hpp>
#include <primes.hpp>
#include <iostream>

using primes::is_prime;
using series::primes;
using generics::digits;
using generics::from_digits;

namespace problems {
    vector<uint> problem49::permutation_primes(const uint& prime) {
        vector<uint> perm_primes(1, prime);
        auto prime_digs = digits(prime);

        for (uint i = 1; i < 24; i++) { // 24 = 4! (the number of permutations)
            next_permutation(prime_digs.begin(), prime_digs.end());
            auto perm_n = from_digits<uint>(prime_digs);
            if (is_prime(perm_n) && find(perm_primes.begin(), perm_primes.end(), perm_n) == perm_primes.end())
                perm_primes.push_back(perm_n);
        }

        return perm_primes;
    }

    ulong problem49::solve() {
        const uint EXCEPT = 1487; // prime not to consider (it's in the example)

        primes<uint> p;
        vector<uint> primes_4_digs = p.get_while([](int n) { return n < 10000; }, [](int n) { return n > 999; });

        ulong result = 0;

        for (const auto &prime : primes_4_digs) {
            vector<uint> perm_primes = permutation_primes(prime);

            if (perm_primes.size() >= 3 && prime != EXCEPT)
                for (auto i = perm_primes.begin() + 1; i < perm_primes.end(); i++) {
                    int diff = *i - prime; // *i is second element in the triple
                    int next = *i + diff; // next is eventual third element
                    if (diff > 0 && find(perm_primes.begin(), perm_primes.end(), next) != perm_primes.end()) {
                        result = (ulong) prime * 100000000;
                        result += *i * 10000;
                        result += next;
                        break;
                    }
                }

            if (result != 0)
                break;
        }

        return result;
    }
}