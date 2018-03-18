//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem48.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <generics.hpp>

using std::vector;
using boost::multiprecision::cpp_int;
using generics::digits;

namespace problems {
    vector<uint32_t> problem48::solve(uint32_t ub) {
        cpp_int sum = 1;

        for (uint32_t i = 2; i <= ub; i++)
            sum += pow((cpp_int) i, i);

        vector<uint32_t> result = digits<uint64_t>((uint64_t) (sum % 10000000000));
        result.insert(result.begin(), 10 - result.size(), 0);
        return result;
    }
}