//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem32.hpp"
#include "unordered_set"
#include "generics.hpp"

using std::vector;
using std::unordered_set;
using generics::digits;

namespace problems {
    uint64_t problem32::combine(uint32_t a, uint32_t b) {
        uint32_t times = 1;
        while (times <= b)
            times *= 10;
        return (uint64_t) a * times + b;
    }

    uint32_t problem32::solve() {
        unordered_set<uint32_t> pandigital_products;
        const vector<uint32_t> all_digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (uint32_t i = 2; i <= 98; i++)
            for (uint32_t j = 123; j <= 4987; j++) {
                uint32_t prod = i * j;
                uint64_t combined = combine(combine(prod, j), i);

                vector<uint32_t> digs = digits(combined);
                sort(digs.begin(), digs.end());
                if (digs == all_digits)
                    pandigital_products.insert(prod);
            }

        uint32_t result = 0;
        for (const auto &n : pandigital_products)
            result += n;
        return result;
    }
}