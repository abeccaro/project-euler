//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM49_HPP
#define PROJECT_EULER_PROBLEM49_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem49 {
    private:
        /**
         * Finds all permutations of given number that are prime
         * @param prime The number. It is supposed to be a prime with 4 digits
         * @return The vector of permutations that are prime
         */
        static std::vector<uint32_t> permutation_primes(const uint32_t& prime);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint64_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM49_HPP
