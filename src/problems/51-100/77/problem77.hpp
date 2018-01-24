//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM77_HPP
#define PROJECT_EULER_PROBLEM77_HPP

#include <vector>

using uint = unsigned int;
using rev_it = std::vector<uint>::reverse_iterator;

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
        static uint primes_combination(uint n, const rev_it& prime);
    public:
        /**
         * Solves problem
         * @param n The number of different prime sums required
         * @return The solution
         */
        static uint solve(uint n = 5000);
    };
}


#endif //PROJECT_EULER_PROBLEM77_HPP
