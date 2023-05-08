//
// Created by Alex Beccaro on 07/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM168_HPP
#define PROJECT_EULER_PROBLEM168_HPP


#include "boost/multiprecision/cpp_int.hpp"
#include "cstdint"
#include "vector"

namespace problems {
    class problem168 {
    private:
        /**
         * Vector of powers of ten, calculated once and stored for performance
         */
        static std::vector<boost::multiprecision::uint512_t> pow10;

        /**
         * Finds the number of digits of given number
         * @param n The number
         * @return The number of digits
         */
        static boost::multiprecision::uint512_t countDigits(const boost::multiprecision::uint512_t& n);

    public:
        /**
         * Finds the last 5 digits of the sum of all numbers that are divisors of their right rotation.
         * It considers numbers with up to the specified number of digits
         * @param ub The maximum number of digits
         * @return The last 5 digits of the sum of all numbers that are divisors of their right rotation
         */
        static uint32_t solve(uint32_t ub = 100);
    };
}


#endif //PROJECT_EULER_PROBLEM168_HPP
