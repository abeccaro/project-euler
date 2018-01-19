//
// Created by Alex Beccaro on 11/12/17.
//

#include "problem4.hpp"
#include "generics.hpp"

using generics::is_palindrome;

namespace problems {
    /**
     * Specifies values, solves problem and outputs solution and calculation time.
     * @return The exit code
     */
    uint problem4::solve(uint digits) {
        uint largest_palindrome = 0;
        uint lb = pow(10, digits-1);
        uint ub = pow(10, digits);

        for (uint i = lb; i < ub; i++)
            for (uint j = i; j < ub; j++) {
                uint n = i * j;
                if (n > largest_palindrome && is_palindrome(n))
                    largest_palindrome = n;
            }

        return largest_palindrome;
    }
}
