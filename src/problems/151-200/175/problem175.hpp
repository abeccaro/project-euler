//
// Created by Alex Beccaro on 22/05/2023.
//

#ifndef PROJECT_EULER_PROBLEM175_HPP
#define PROJECT_EULER_PROBLEM175_HPP


#include "cstdint"
#include "string"

namespace problems {
    class problem175 {
    public:
        /**
         * Finds the smallest number for which f(n) / f(n - 1) = numerator/denominator, where f(n) is the number of ways
         * to write n as a sum of powers of where no power occurs more than twice.
         * The result is given in the Shortened Binary Expansion form
         * @param numerator The numerator f(n)
         * @param denominator The denominator f(n - 1)
         * @return The smallest number for which f(n) / f(n - 1) = numerator/denominator in Shortened Binary Expansion
         * form
         */
        static std::string solve(uint32_t numerator = 123456789, uint32_t denominator = 987654321);
    };
}


#endif //PROJECT_EULER_PROBLEM175_HPP
