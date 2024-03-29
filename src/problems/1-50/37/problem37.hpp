//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM37_HPP
#define PROJECT_EULER_PROBLEM37_HPP

#include "cstdint"

namespace problems {
    class problem37 {
    private:
        /**
         * Checks if given prime is truncatable from left to right
         * @param n The prime
         * @return True if the prime is truncatable from left to right, false otherwise.
         */
        static bool is_truncatable_from_left(const uint64_t& n);

        /**
         * Checks if given prime is truncatable from right to left
         * @param n The prime
         * @return True if the prime is truncatable from right to left, false otherwise.
         */
        static bool is_truncatable_from_right(const uint64_t& n);
    public:
        /**
         * Solves problem
         * @param n The number of truncatable primes to find
         * @return The solution
         */
        static uint64_t solve(uint64_t n = 11);
    };
}


#endif //PROJECT_EULER_PROBLEM37_HPP
