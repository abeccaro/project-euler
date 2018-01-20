//
// Created by Alex Beccaro on 21/12/17.
//

#include "problem36.hpp"
#include <generics.hpp>

using generics::is_palindrome;
using generics::to_base;

namespace problems {
    uint problem36::solve(uint ub) {
        uint result = 0;
        for (uint i = 1; i < ub; i++)
            if (is_palindrome(i)) {
                vector<uint> digs = to_base(i, 2);
                vector<uint> rev_digs(digs.size());

                reverse_copy(digs.begin(), digs.end(), rev_digs.begin());

                if (digs == rev_digs)
                    result += i;
            }
        return result;
    }
}