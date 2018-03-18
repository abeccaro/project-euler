//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem49.hpp"
#include <series/primes.hpp>
#include <generics.hpp>
#include <primes.hpp>
#include <iostream>

using std::vector;
using primes::is_prime;
using series::primes;
using generics::digits;
using generics::from_digits;

namespace problems {
    vector<uint32_t> problem49::permutation_primes(const uint32_t& prime) {
        vector<uint32_t> perm_primes(1, prime);
        auto prime_digs = digits(prime);

        for (uint32_t i = 1; i < 24; i++) { // 24 = 4! (the number of permutations)
            next_permutation(prime_digs.begin(), prime_digs.end());
            auto perm_n = from_digits<uint32_t>(prime_digs);
            if (is_prime(perm_n) && find(perm_primes.begin(), perm_primes.end(), perm_n) == perm_primes.end())
                perm_primes.push_back(perm_n);
        }

        return perm_primes;
    }

    uint64_t problem49::solve() {
        const uint32_t except = 1487; // prime not to consider (it's in the example)

        primes<uint32_t> p;
        vector<uint32_t> primes_4_digs = p.get_while([](int n) { return n < 10000; }, [](int n) { return n > 999; });

        uint64_t result = 0;

        for (const auto &prime : primes_4_digs) {
            vector<uint32_t> perm_primes = permutation_primes(prime);

            if (perm_primes.size() >= 3 && prime != except)
                for (auto i = perm_primes.begin() + 1; i < perm_primes.end(); i++) {
                    int diff = *i - prime; // *i is second element in the triple
                    int next = *i + diff; // next is eventual third element
                    if (diff > 0 && find(perm_primes.begin(), perm_primes.end(), next) != perm_primes.end()) {
                        result = (uint64_t) prime * 100000000;
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