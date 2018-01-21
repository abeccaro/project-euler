//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem57.hpp"
#include <fraction.hpp>
#include <series/sqrt_convergents.hpp>

using fractions::fraction;
using series::sqrt_convergents;
using boost::multiprecision::cpp_int;

namespace problems {
    uint problem57::solve(uint convergents) {
        uint result = 0;
        sqrt_convergents<cpp_int> c(2);

        for (uint i = 0; i <= convergents; i++) {
            cpp_int num = c[i].get_numerator();
            cpp_int den = c[i].get_denominator();
            if (num.str().size() > den.str().size())
                result++;
        }

        return result;
    }
}