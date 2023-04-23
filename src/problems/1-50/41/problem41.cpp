//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem41.hpp"
#include "generics.hpp"
#include "primes.hpp"

using std::vector;
using generics::from_digits;
using generics::factorial;
using primes::is_prime;

namespace problems {
    uint64_t problem41::solve() {
        vector<uint32_t> all_digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        uint64_t result;

        // 9,8,6,5,3,2 -digit pandigitals cannot be primes (always dividable by 3)
        // so only 7,4,1 -digit numbers are tested
        for (uint32_t n = 7; n > 0; n -= 3) {
            vector<uint32_t> permutation(n);
            copy(all_digits.begin(), all_digits.begin() + n, permutation.begin());

            uint64_t max = 0;

            uint32_t permutations = factorial(n);
            for (uint32_t i = 0; i < permutations; i++) {
                next_permutation(permutation.begin(), permutation.end());
                uint64_t number = from_digits<uint64_t>(permutation);

                if (is_prime(number) && number > max)
                    max = number;
            }

            if (max != 0) {
                result = max;
                break;
            }
        }

        return result;
    }
}