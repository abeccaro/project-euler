//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem46.hpp"
#include <primes.hpp>
#include <series/primes.hpp>

using primes::is_prime;

namespace problems {
    uint32_t problem46::solve() {
        series::primes<uint32_t> p;
        uint32_t result = 0;

        for (uint32_t i = 9; result == 0; i += 2)
            if (!is_prime(i)) {
                bool found = false;
                
                for (auto prime = p.begin(); *prime < i; prime++) {
                    uint32_t x = (i - *prime) / 2;
                    auto root = sqrt(x);
                    if (root == (uint32_t) root) {
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