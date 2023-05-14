//
// Created by Alex Beccaro on 08/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM169_HPP
#define PROJECT_EULER_PROBLEM169_HPP


#include "boost/functional/hash.hpp"
#include "boost/multiprecision/cpp_int.hpp"
#include "generics.hpp"
#include "unordered_map"

namespace problems {
    class problem169 {
    private:
        /**
         * Memoization values for f(n, p)
         */
        static std::unordered_map<
                        std::pair<boost::multiprecision::uint128_t, boost::multiprecision::uint128_t>,
                        uint64_t,
                        boost::hash<std::pair<boost::multiprecision::uint128_t, boost::multiprecision::uint128_t>>
                > mem;

        /**
         * Calculates the number of ways to express n as a sum of powers of 2 using each power less than or equal
         * max_pow no more than twice
         * @param n The number
         * @param max_pow The maximum power of 2 allowed
         * @return The number of ways
         */
        static uint64_t f(const boost::multiprecision::uint128_t& n, const boost::multiprecision::uint128_t& max_pow);

    public:
        /**
         * Calculates the number of ways to express n as a sum of powers of 2 using each power no more than twice
         * @param n The number
         * @return The number of ways
         */
        static uint64_t solve(const boost::multiprecision::uint128_t& n = generics::int_pow<boost::multiprecision::uint128_t>(10, 25));
    };
}


#endif //PROJECT_EULER_PROBLEM169_HPP
