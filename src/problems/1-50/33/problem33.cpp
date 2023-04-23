//
// Created by Alex Beccaro on 19/12/17.
//

#include "problem33.hpp"
#include "generics.hpp"

using generics::gcd;

namespace problems {
    bool problem33::is_digit_cancelling(uint32_t n, uint32_t d) {
        uint32_t n1 = n / 10;
        uint32_t n2 = n % 10;
        uint32_t d1 = d / 10;
        uint32_t d2 = d % 10;
        uint32_t gcd_nd = gcd(n, d);

        return (n1 == d1 && n / gcd_nd == n2 / gcd(n2, d2) && d / gcd_nd == d2 / gcd(n2, d2)) ||
               (n1 == d2 && n / gcd_nd == n2 / gcd(n2, d1) && d / gcd_nd == d1 / gcd(n2, d1)) ||
               (n2 == d1 && n / gcd_nd == n1 / gcd(n1, d2) && d / gcd_nd == d2 / gcd(n1, d2)) ||
               (n2 == d2 && n / gcd_nd == n1 / gcd(n1, d1) && d / gcd_nd == d1 / gcd(n1, d1));

    }

    uint32_t problem33::solve() {
        uint32_t num_product = 1;
        uint32_t den_product = 1;

        for (uint32_t n = 10; n < 100; n++)
            for (uint32_t d = n + 1; d < 100; d++)
                if (d % 10 != 0 && is_digit_cancelling(n, d)) {
                    num_product *= n;
                    den_product *= d;
                }

        return den_product / gcd(num_product, den_product);
    }
}