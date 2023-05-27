//
// Created by Alex Beccaro on 08/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM169_HPP
#define PROJECT_EULER_PROBLEM169_HPP


#include "boost/multiprecision/cpp_int.hpp"
#include "generics.hpp"
#include "unordered_map"

namespace problems {
    class problem169 {
    public:
        /**
         * Memoization values for f(n)
         */
        static std::unordered_map<boost::multiprecision::uint128_t, uint64_t> mem;

        /**
         * Calculates the number of ways to express n as a sum of powers of 2 using each power no more than twice
         * in a recursive way. Used as a helper for the main solve function.
         * @param n The number
         * @return The number of ways
         */
        static uint64_t f(const boost::multiprecision::uint128_t& n);

        /**
         * Calculates the number of ways to express n as a sum of powers of 2 using each power no more than twice
         * @param n The number
         * @return The number of ways
         */
        static uint64_t solve(const boost::multiprecision::uint128_t& n = generics::int_pow<boost::multiprecision::uint128_t>(10, 25));
    };
}


#endif //PROJECT_EULER_PROBLEM169_HPP
