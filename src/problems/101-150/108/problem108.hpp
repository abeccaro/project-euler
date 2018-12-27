//
// Created by Alex Beccaro on 05/12/18.
//

#ifndef PROJECT_EULER_PROBLEM108_HPP
#define PROJECT_EULER_PROBLEM108_HPP

#include <cstdint>
#include <series/primes.hpp>

namespace problems {
    class problem108 {
    private:
        /**
         * Finds recursively the lowest number n to have at least 'solutions' distinct
         * solutions to 1/x + 1/y = 1/n.
         *
         * @param solutions The lower bound of solutions to find
         * @param best The best n found so far
         * @param p The next prime factor to consider
         * @param max_mult_p The maximum multeplicity of p to consider
         * @param n Current number
         * @param sol_found Current number of solutions found
         * @return The lowest number n to have at least 'solutions' distinct solutions.
         */
        static uint32_t find_num(uint32_t solutions, uint32_t best, const series::primes<uint32_t>::iterator& p,
                                 uint32_t max_mult_p, uint32_t n, uint32_t sol_found);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint64_t solve(uint32_t n = 1000);
    };
}


#endif //PROJECT_EULER_PROBLEM108_HPP
