//
// Created by Alex Beccaro on 16/01/2019.
//

#ifndef PROJECT_EULER_PROBLEM118_HPP
#define PROJECT_EULER_PROBLEM118_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem118 {
    private:
        /**
         * Calculates the number of sets that contain only primes obtained by partitioning given digit set 'v'.
         * All of the numbers have to be used. Only ordered sets are considered.
         * @param v The vector of digits
         * @return The number of sets of prime
         */
        static uint32_t prime_sets(const std::vector<uint32_t>& v);

        /**
         * Helper recursive function for prime_sets.
         * @param v The vector of digits
         * @param set The partial set of primes
         * @return The number of sets of prime
         */
        static uint32_t prime_sets(const std::vector<uint32_t>& v, std::vector<uint32_t>& set);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM118_HPP
