//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem48.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <generics.hpp>

using boost::multiprecision::cpp_int;
using generics::digits;

namespace problems {
    vector<uint> problem48::solve(uint ub) {
        cpp_int sum = 1;

        for (uint i = 2; i <= ub; i++)
            sum += pow((cpp_int) i, i);

        vector<uint> result = digits<cpp_int>(sum % 10000000000);
        result.insert(result.begin(), 10 - result.size(), 0);
        return result;
    }
}