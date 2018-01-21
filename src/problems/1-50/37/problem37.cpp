//
// Created by Alex Beccaro on 03/01/18.
//

#include "problem37.hpp"
#include <series/primes.hpp>
#include <primes.hpp>

using primes::is_prime;
using series::primes;
using generics::digits;
using generics::from_digits;

namespace problems {
    bool problem37::is_truncatable_from_left(const ulong &n) {
        vector<uint> digs = digits(n);

        while (digs.size() > 1) {
            if (!is_prime(from_digits<ulong>(digs)))
                return false;
            digs.erase(digs.begin());
        }

        return is_prime(digs[0]);
    }

    bool problem37::is_truncatable_from_right(const ulong &n) {
        ulong copy = n;

        while (copy >= 10) {
            if (!is_prime(copy))
                return false;
            copy = copy / 10;
        }

        return is_prime(copy);
    }

    ulong problem37::solve(ulong n) {
        primes<ulong> p;
        vector<ulong> numbers = p.get(n, [](ulong p) {
            return p >= 10 && is_truncatable_from_left(p) && is_truncatable_from_right(p);
        });

        ulong result = 0;
        for (const auto &n : numbers)
            result += n;
        return result;
    }
}