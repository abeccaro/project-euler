//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem46.hpp"
#include <primes.hpp>
#include <series/primes.hpp>

using primes::is_prime;
using series::primes;

namespace problems {
    uint problem46::solve() {
        primes<uint> p;
        uint result = 0;

        for (uint i = 9; result == 0; i += 2)
            if (!is_prime(i)) {
                bool found = false;
                
                for (auto prime = p.begin(); *prime < i; prime++) {
                    uint x = (i - *prime) / 2;
                    auto root = sqrt(x);
                    if (root == (uint) root) {
                        found = true;
                        break;
                    }
                }

                if (!found)
                    result = i;
            }

        return result;
    }
}