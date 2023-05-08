//
// Created by Alex Beccaro on 07/05/2023.
//

#include "generics.hpp"
#include "problem168.hpp"


using boost::multiprecision::uint512_t;
using generics::int_pow;
using std::vector;

namespace problems {
    vector<uint512_t> problem168::pow10;

    uint512_t problem168::countDigits(const uint512_t& n) {
        return to_string(n).size();
    }

    uint32_t problem168::solve(uint32_t ub) {
        // precalculate and store powers of 10
        pow10 = {};
        for (uint512_t i = 0; i <= ub; i++)
            pow10.push_back(int_pow<uint512_t>(10, i));

        // We are looking for all integer x with d digits in equation x = f(10^d - 1)/(10k - 1) where
        // f = last digit of x
        // d = number of digits of x
        // k = factor for x and its right rotation
        uint32_t res = 0;
        for (uint32_t d = 2; d <= ub; d++) {
            for (uint512_t f = 1; f <= 9; f++) {
                uint512_t num = (pow10[d] - 1) * f;
                for (uint512_t k = 1; k <= 9; k++) {
                    uint512_t den = 10 * k - 1;
                    if (num % den != 0)
                        continue;

                    uint512_t x = num / den;
                    if (countDigits(x) == d)
                        res += (uint32_t) (x % 100000);
                }
            }
        }

        return res % 100000;
    }
}