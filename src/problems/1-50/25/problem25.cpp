//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem25.hpp"
#include <series/fibonacci.hpp>
#include <generics.hpp>

using boost::multiprecision::cpp_int;
using series::fibonacci;

namespace problems {
    ulong problem25::solve(uint digs) {
        fibonacci<cpp_int> f;
        cpp_int lb = pow((cpp_int) 10, digs-1);
        f.get_first([lb](cpp_int n) {return n > lb;});
        return f.size();
    }
}