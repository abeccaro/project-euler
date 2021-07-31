//
// Created by Alex Beccaro on 09/12/2020.
//

#include "problem148.hpp"
#include <generics.hpp>

using generics::int_pow;
using boost::multiprecision::cpp_int;


namespace problems {

    cpp_int problem148::triangular(const cpp_int& x) {
        return x * (x+1) / 2;
    }

    // Solves recursive formula f(a * 7^k + b) = T_a * T_7^k + (a+1) * f(b) for n = a * 7^k + b
    cpp_int problem148::solve(const cpp_int& n) {
        if (n <= 7)
            return triangular(n);

        cpp_int k = 0;
        while (int_pow<cpp_int>(7, k+1) < n)
            k++;

        cpp_int seven_k = int_pow<cpp_int>(7, k);
        cpp_int a = n / seven_k;
        cpp_int b = n % seven_k;

        return triangular(a) * int_pow(triangular(7), k) + (a + 1) * solve(b);
    }

}