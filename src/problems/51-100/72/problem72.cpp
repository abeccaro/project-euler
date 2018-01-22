//
// Created by Alex Beccaro on 22/01/18.
//

#include <generics.hpp>
#include "problem72.hpp"

using generics::totient;

namespace problems {
    ulong problem72::solve(ulong ub) {
        ulong result = 0;

        for (ulong i = 2; i <= ub; i++)
            result += totient(i);

        return result;
    }
}
