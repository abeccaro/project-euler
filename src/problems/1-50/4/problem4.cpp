//
// Created by Alex Beccaro on 11/12/17.
//

#include "problem4.hpp"
#include "generics.hpp"

using generics::is_palindrome;

namespace problems {
    uint32_t problem4::solve(uint32_t digits) {
        uint32_t largest_palindrome = 0;
        uint32_t lb = (uint32_t) pow(10, digits-1);
        uint32_t ub = lb * 10;

        for (uint32_t i = lb; i < ub; i++)
            for (uint32_t j = i; j < ub; j++) {
                uint32_t n = i * j;
                if (n > largest_palindrome && is_palindrome(n))
                    largest_palindrome = n;
            }

        return largest_palindrome;
    }
}
