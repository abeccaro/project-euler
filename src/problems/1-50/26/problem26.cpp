//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem26.hpp"
#include "generics.hpp"

using boost::multiprecision::cpp_int;
using generics::are_coprime;
using generics::multiplicative_order;

namespace problems {
    uint32_t problem26::solve(uint32_t ub) {
        cpp_int longest = 0;
        uint32_t result = 1;

        for (uint32_t i = 2; i < ub; i++)
            if (are_coprime<uint32_t>(10, i)) {
                cpp_int mo = multiplicative_order<cpp_int>(10, i);
                if (mo > longest) {
                    longest = mo;
                    result = i;
                }
            }

        return result;
    }
}