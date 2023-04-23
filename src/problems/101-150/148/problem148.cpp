//
// Created by Alex Beccaro on 09/12/2020.
//

#include "problem148.hpp"
#include "generics.hpp"

using generics::int_pow;


namespace problems {

    uint64_t problem148::triangular(uint64_t x) {
        return x * (x+1) / 2;
    }

    // Solves recursive formula f(a * 7^k + b) = T_a * T_7^k + (a+1) * f(b) for n = a * 7^k + b
    uint64_t problem148::solve(uint64_t n) {
        if (n <= 7)
            return triangular(n);

        uint64_t k = 0;
        while (int_pow(7ull, k+1) < n)
            k++;

        uint64_t seven_k = int_pow(7ull, k);
        uint64_t a = n / seven_k;
        uint64_t b = n % seven_k;

        return triangular(a) * int_pow(triangular(7), k) + (a + 1) * solve(b);
    }

}