//
// Created by Alex Beccaro on 17/12/2019.
//

#include "problem142.hpp"
#include "series/figurate_number.hpp"
#include "generics.hpp"
#include "cmath"


using std::get;
using std::vector;
using std::unordered_map;

using generics::are_coprime;

using triple = std::tuple<uint32_t, uint32_t, uint32_t>;


namespace problems {

    triple problem142::shared_triples(unordered_map<uint32_t, vector<triple>>& triples, uint32_t a, uint32_t c) {
        for (const auto& t1 : triples[a])
            for (const auto& t2 : triples[c])
                if (get<1>(t1) == get<0>(t2))
                    return {get<0>(t1), get<1>(t2), get<1>(t1)};
        return {0, 0, 0};
    }

    /*
     * x + y = a^2
     * x + z = b^2
     * y + z = c^2
     * x - y = d^2
     * x - z = e^2
     * y - z = f^2
     *
     * So the following are ordered pythagorean triples:
     * (d, f, e) (d, c, b) (f, b, a) (e, c, a)
     *
     * Search for triples with this property and calculate:
     * x = (a^2 + d^2) / 2 (x must be integer => numerator must be even!)
     * y = a^2 - x
     * z = b^2 - z
     */
    uint32_t problem142::solve() {
        uint32_t ub = 1000; // max hypotenuse for Pythagorean triples to check
        unordered_map<uint32_t, vector<triple>> triples; // store all triples indexed by hypotenuse
        for (uint32_t i = 0; i < ub; i++)
            triples[i] = {};

        // generate triples
        for (uint32_t m = 2; m < sqrtl(ub); m++) {
            for (uint32_t n = 1; n < m; n++) {
                if (!are_coprime(m, n) || (m % 2 == 1 && n % 2 == 1))
                    continue;

                uint32_t t1 = m * m - n * n;
                uint32_t t2 = 2 * m * n;
                uint32_t t3 = m * m + n * n;

                if (t1 % 2 == 0) {
                    uint32_t temp = t1;
                    t1 = t2;
                    t2 = temp;
                }

                for (uint32_t k = 1; k * t3 < ub; k++) {
                    uint32_t e = (t1 > t2 ? t2 : t1) * k;
                    uint32_t c = (t1 > t2 ? t1 : t2) * k;
                    uint32_t a = t3 * k;

                    triples[a].emplace_back(e, c, a);
                }
            }
        }

        // search for solution using generated triples
        for (const auto& v : triples) {
            for (const auto& t : v.second) {
                uint32_t e = get<0>(t);
                uint32_t c = get<1>(t);
                uint32_t a = get<2>(t);

                triple res = shared_triples(triples, e, a);
                uint32_t d = get<0>(res);
                uint32_t b = get<1>(res);
                uint32_t f = get<2>(res);

                if (d != 0 && (a * a + d * d) % 2 == 0) {
                    uint32_t x = (a * a + d * d) / 2;
                    uint32_t y = a * a - x;
                    uint32_t z = b * b - x;

                    return x + y + z;
                }
            }
        }
    }

}