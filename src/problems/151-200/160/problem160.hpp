//
// Created by Alex Beccaro on 17/09/2022.
//

#ifndef PROJECT_EULER_PROBLEM160_HPP
#define PROJECT_EULER_PROBLEM160_HPP


#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

namespace problems {
    class problem160 {
    private:
        /**
         * Calculates the multiplicity of a prime in the factorization of a number factorial
         * @param p The prime
         * @param n The number
         * @return The multiplicity of p in n! factorization
         */
        static uint64_t multiplicity_in_factorial(uint64_t p, uint64_t n);

    public:
        /**
         * Calculates last x non-zero digits of n!
         * @param n The number
         * @param digits The number of digits
         * @return The last x digits of n!
         */
        static uint64_t solve(uint64_t n = 1000000000000, uint64_t digits = 5);
    };
}


#endif //PROJECT_EULER_PROBLEM160_HPP
