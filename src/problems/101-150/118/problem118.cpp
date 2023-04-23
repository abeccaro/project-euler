//
// Created by Alex Beccaro on 16/01/2019.
//

#include "problem118.hpp"
#include "generics.hpp"
#include "primes.hpp"


using std::vector;

using primes::is_prime;
using generics::from_digits;


namespace problems {

    uint32_t problem118::prime_sets(const vector<uint32_t>& v) {
        vector<uint32_t> set = {};
        return prime_sets(v, set);
    }

    uint32_t problem118::prime_sets(const vector<uint32_t>& v, vector<uint32_t>& set) {
        if (v.empty())
            return 1;

        uint32_t res = 0;

        for (uint32_t i = 1; i <= v.size(); i++) {
            uint64_t n = from_digits<uint64_t>({v.begin(), v.begin() + i});

            if ((set.empty() || n > set.back()) && is_prime(n)) {
                set.push_back(n);
                res += prime_sets({v.begin() + i, v.end()}, set);
                set.pop_back();
            }
        }

        return res;
    }

    uint32_t problem118::solve() {
        vector<uint32_t> digs = {1, 2, 3, 4, 5, 6, 7, 8, 9};


        uint32_t res = 0;
        do {
            if (digs.back() % 2 != 0)
                res += prime_sets(digs);
        } while ( next_permutation(digs.begin(), digs.end()) );

        return res;
    }

}