//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem55.hpp"
#include <generics.hpp>

using generics::digits;
using generics::from_digits;
using generics::is_palindrome;

namespace problems {
    uint problem55::solve(uint ub, uint iterations) {
        uint result = ub - 1;
        for (uint i = 1; i < ub; i++) {
            ulong n = i;
            bool lychrel = true;
            for (uint j = 0; j < iterations; j++) {
                auto digs = digits(n);
                reverse(digs.begin(), digs.end());
                n = n + from_digits<ulong>(digs);
                if (is_palindrome(n)) {
                    result--;
                    break;
                }
            }
        }
        return result;
    }
}