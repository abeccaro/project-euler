//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem26.hpp"
#include <generics.hpp>

using boost::multiprecision::cpp_int;
using namespace generics;

namespace problems {
    uint problem26::solve(uint ub) {
        cpp_int longest = 0;
        uint result = 1;

        for (uint i = 2; i < ub; i++)
            if (are_coprime<uint>(10, i)) {
                auto mo = multiplicative_order<cpp_int>(10, i);
                if (mo > longest) {
                    longest = mo;
                    result = i;
                }
            }

        return result;
    }
}