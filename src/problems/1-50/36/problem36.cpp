//
// Created by Alex Beccaro on 21/12/17.
//

#include "problem36.hpp"
#include <generics.hpp>

using std::vector;
using generics::is_palindrome;
using generics::to_base;

namespace problems {
    uint32_t problem36::solve(uint32_t ub) {
        uint32_t result = 0;
        for (uint32_t i = 1; i < ub; i++)
            if (is_palindrome(i)) {
                vector<uint32_t> digs = to_base(i, 2);
                vector<uint32_t> rev_digs(digs.size());

                reverse_copy(digs.begin(), digs.end(), rev_digs.begin());

                if (digs == rev_digs)
                    result += i;
            }
        return result;
    }
}