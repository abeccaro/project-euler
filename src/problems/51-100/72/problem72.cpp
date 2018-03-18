//
// Created by Alex Beccaro on 22/01/18.
//

#include <generics.hpp>
#include "problem72.hpp"

using generics::totient;

namespace problems {
    uint64_t problem72::solve(uint64_t ub) {
        uint64_t result = 0;

        for (uint64_t i = 2; i <= ub; i++)
            result += totient(i);

        return result;
    }
}
