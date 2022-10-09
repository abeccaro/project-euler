//
// Created by Alex Beccaro on 17/09/2022.
//

#include "problem160.hpp"
#include "generics.hpp"

using std::min;
using std::max;
using std::vector;
using generics::int_pow;
using generics::mod_pow;

namespace problems {
    uint64_t problem160::multiplicity_in_factorial(uint64_t p, uint64_t n) {
        uint64_t count = 0;
        for (uint64_t i = p; i <= n; i *= p)
            count += n / i;
        return count;
    }

    uint64_t problem160::solve(uint64_t n, uint64_t digits) {
        uint64_t mod = int_pow(10ull, digits);
        uint64_t res = 1;

        vector<uint64_t> two_five_powers;
        for (uint64_t i = 1; i <= n; i *= 2) {
            for (uint64_t j = i; j <= n; j *= 5)
                two_five_powers.push_back(j);
        }
        two_five_powers.erase(two_five_powers.begin()); // remove 1

        uint64_t k = max(n / mod, 1ull);
        for (uint64_t i = 1; i <= min(n, mod); i += 2) {
            if (i % 5 == 0)
                continue;

            uint64_t count = k;
            for (const auto& p : two_five_powers)
                count += k / p + ((k / p * mod + i) * p <= n ? 1 : 0);

            res = (res * mod_pow(i, count, mod)) % mod;
        }

        uint64_t two_exp = multiplicity_in_factorial(2, n) - multiplicity_in_factorial(5, n);
        res = (res * mod_pow(2ull, two_exp, mod)) % mod;

        return res;
    }
}