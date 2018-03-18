//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM77_HPP
#define PROJECT_EULER_PROBLEM77_HPP

#include <vector>

namespace problems {
    class problem77 {
    private:
        /**
         * Counts the possible different ways in which n can be obtained summing primes (order doesn't matter).
         * Primes in collection are supposed in order.
         * @param n The sum
         * @param coin The maximum value prime to use
         * @return The number of different prime sums to n
         */
        static uint32_t primes_combination(uint32_t n, const std::vector<uint32_t>::reverse_iterator& prime);
    public:
        /**
         * Solves problem
         * @param n The number of different prime sums required
         * @return The solution
         */
        static uint32_t solve(uint32_t n = 5000);
    };
}


#endif //PROJECT_EULER_PROBLEM77_HPP
