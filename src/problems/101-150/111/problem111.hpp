//
// Created by Alex Beccaro on 27/12/18.
//

#ifndef PROJECT_EULER_PROBLEM111_HPP
#define PROJECT_EULER_PROBLEM111_HPP

#include <cstdint>
#include <string>

namespace problems {
    class problem111 {
    private:
        /**
         * Calculates the sum of the primes obtained from given bitmask, where 1 -> 'digit' and 0 -> different digit
         * @param bitmask The numbers bitmask
         * @param digit The repeating digit
         * @return The sum of the primes obtained from given bitmask
         */
        static uint64_t primes_sum_from_bitmask(const std::string bitmask, uint32_t digit);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint64_t solve(uint32_t n = 10);
    };
}


#endif //PROJECT_EULER_PROBLEM111_HPP
