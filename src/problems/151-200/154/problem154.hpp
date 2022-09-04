//
// Created by Alex Beccaro on 02/09/2022.
//

#ifndef PROJECT_EULER_PROBLEM154_HPP
#define PROJECT_EULER_PROBLEM154_HPP


#include <cstdint>
#include <vector>

namespace problems {
    class problem154 {
    private:
        /**
         * Calculates the exponent of p in n prime factorization
         * @param n The number
         * @param p The prime
         * @return The exponent of p in n prime factorization
         */
        static uint32_t prime_multiplicity(uint32_t n, uint32_t p);

        /**
         * Calculates the multiplicity of factors 2 and 5 for the factorials of numbers up to n. The resulting vector
         * contains the pair of multiplicities for x at index x.
         * @param n The upper bound for numbers
         * @return The multiplicity of factors 2 and 5 for the factorials of numbers up to n
         */
        static std::vector<std::pair<uint32_t, uint32_t>> factorial_multiplicity_2_5(uint32_t n);

    public:
        /**
         * Calculates how many coefficients in the expansion of (x + y + z)^n are multiples of 10^exp
         * @param n The exponent of the trinomial expansion
         * @param exp The exponent of ten to count multiples of
         * @return The number of coefficients multiples of 10^exp
         */
        static uint32_t solve(uint32_t n = 200000, uint32_t exp = 12);
    };
}


#endif //PROJECT_EULER_PROBLEM154_HPP
