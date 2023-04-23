//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem55.hpp"
#include "generics.hpp"

using generics::digits;
using generics::from_digits;
using generics::is_palindrome;

namespace problems {
    uint32_t problem55::solve(uint32_t ub, uint32_t iterations) {
        uint32_t result = ub - 1;
        for (uint32_t i = 1; i < ub; i++) {
            uint64_t n = i;
            bool lychrel = true;
            for (uint32_t j = 0; j < iterations; j++) {
                auto digs = digits(n);
                reverse(digs.begin(), digs.end());
                n = n + from_digits<uint64_t>(digs);
                if (is_palindrome(n)) {
                    result--;
                    break;
                }
            }
        }
        return result;
    }
}