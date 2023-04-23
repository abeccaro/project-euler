//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem57.hpp"
#include "fraction.hpp"
#include "series/sqrt_convergents.hpp"

using fractions::fraction;
using series::sqrt_convergents;
using boost::multiprecision::cpp_int;

namespace problems {
    uint32_t problem57::solve(uint32_t convergents) {
        uint32_t result = 0;
        sqrt_convergents<cpp_int> c(2);

        for (uint32_t i = 0; i <= convergents; i++) {
            cpp_int num = c[i].numerator();
            cpp_int den = c[i].denominator();
            if (num.str().size() > den.str().size())
                result++;
        }

        return result;
    }
}