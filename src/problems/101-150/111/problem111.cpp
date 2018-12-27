//
// Created by Alex Beccaro on 27/12/18.
//

#include "problem111.hpp"
#include <primes.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using primes::is_prime;
using generics::from_digits;
using generics::combinations_repetition;
using std::vector;
using std::string;

using boost::multiprecision::uint128_t;

namespace problems {
    uint64_t problem111::primes_sum_from_bitmask(const std::string bitmask, uint32_t digit) {
        uint64_t n = bitmask.size(), m = 0;
        vector<uint32_t> digits(n);

        for (uint32_t i = 0; i < n; ++i) {
            if (bitmask[i]) {
                digits[i] = digit;
                m++;
            } else
                digits[i] = digit + 1;
        }

        vector<uint32_t> all = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        all.erase(std::remove(all.begin(), all.end(), digit), all.end());
        auto combs = combinations_repetition(all, n - m);

        uint64_t sum = 0;
        for (const auto &c : combs) {
            vector<uint32_t> digs(digits);
            uint32_t j = 0;

            for (uint32_t i = 0; i < digs.size(); i++)
                if (digs[i] != digit)
                    digs[i] = c[j++];


            uint64_t num = from_digits<uint64_t>(digs);
            if (digs[0] != 0 && is_prime<uint128_t>(num))
                sum += num;
        }

        return sum;
    }

    uint64_t problem111::solve(uint32_t n) {
        uint64_t res = 0;

        for (uint32_t d = 0; d < 10; d++) {
            uint32_t m = n;
            uint64_t sum = 0;
            bool found_m = false;

            while (!found_m) {
                m--;

                string bitmask(m, 1); // 1 -> d
                bitmask.resize(n, 0); // 0 -> !d

                do {
                    uint64_t s = primes_sum_from_bitmask(bitmask, d);

                    if (s > 0) {
                        found_m = true;
                        sum += s;
                    }
                } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
            }

            res += sum;
        }

        return res;
    }
}