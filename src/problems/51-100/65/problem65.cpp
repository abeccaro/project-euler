//
// Created by Alex Beccaro on 14/01/18.
//

#include "problem65.hpp"
#include "fraction.hpp"
#include "generics.hpp"

using std::vector;
using boost::multiprecision::uint512_t;
using fractions::fraction;
using generics::digits;

namespace problems {
    uint32_t problem65::solve(uint32_t n) {
        fraction<uint512_t> convergent = 1; // general formula: N % 3 == 0 ? 2 * N / 3 : 1
        for (uint32_t i = n - 1; i > 1; i--) {
            convergent.invert();
            if (i % 3 == 0)
                convergent += 2 * i / 3;
            else
                convergent += 1;
        }
        convergent.invert();
        convergent += 2;
        convergent.reduce();

        uint32_t result = 0;
        vector<uint32_t> digs = digits(convergent.numerator());
        for (const auto &d : digs)
            result += d;
        return result;
    }
}