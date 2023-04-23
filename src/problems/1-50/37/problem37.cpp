//
// Created by Alex Beccaro on 03/01/18.
//

#include "problem37.hpp"
#include "series/primes.hpp"
#include "primes.hpp"
#include "generics.hpp"

using std::vector;
using primes::is_prime;
using generics::digits;
using generics::from_digits;

namespace problems {
    bool problem37::is_truncatable_from_left(const uint64_t &n) {
        vector<uint32_t> digs = digits(n);

        while (digs.size() > 1) {
            if (!is_prime(from_digits<uint64_t>(digs)))
                return false;
            digs.erase(digs.begin());
        }

        return is_prime(digs[0]);
    }

    bool problem37::is_truncatable_from_right(const uint64_t &n) {
        uint64_t copy = n;

        while (copy >= 10) {
            if (!is_prime(copy))
                return false;
            copy = copy / 10;
        }

        return is_prime(copy);
    }

    uint64_t problem37::solve(uint64_t n) {
        series::primes<uint64_t> p;
        vector<uint64_t> numbers = p.get(n, [](uint64_t p) {
            return p >= 10 && is_truncatable_from_left(p) && is_truncatable_from_right(p);
        });

        uint64_t result = 0;
        for (const auto &x : numbers)
            result += x;
        return result;
    }
}