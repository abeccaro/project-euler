//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem41.hpp"
#include <generics.hpp>
#include <primes.hpp>

using generics::from_digits;
using generics::factorial;
using primes::is_prime;

using uint = unsigned int;

namespace problems {
    ulong problem41::solve() {
        vector<uint> ALL_DIGITS = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        ulong result;

        // 9,8,6,5,3,2 -digit pandigitals cannot be primes (always dividable by 3)
        // so only 7,4,1 -digit numbers are tested
        for (uint n = 7; n > 0; n -= 3) {
            vector<uint> permutation(n);
            copy(ALL_DIGITS.begin(), ALL_DIGITS.begin() + n, permutation.begin());

            ulong max = 0;

            uint permutations = factorial(n);
            for (uint i = 0; i < permutations; i++) {
                next_permutation(permutation.begin(), permutation.end());
                auto number = from_digits<ulong>(permutation);

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