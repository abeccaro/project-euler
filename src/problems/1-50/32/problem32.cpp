//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem32.hpp"
#include <unordered_set>
#include <generics.hpp>

using generics::digits;

namespace problems {
    ulong problem32::combine(uint a, uint b) {
        uint times = 1;
        while (times <= b)
            times *= 10;
        return (ulong) a * times + b;
    }

    uint problem32::solve() {
        unordered_set<uint> pandigital_products;
        const vector<uint> all_digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (uint i = 2; i <= 98; i++)
            for (uint j = 123; j <= 4987; j++) {
                uint prod = i * j;
                ulong combined = combine(combine(prod, j), i);

                vector<uint> digs = digits(combined);
                sort(digs.begin(), digs.end());
                if (digs == all_digits)
                    pandigital_products.insert(prod);
            }

        uint result = 0;
        for (const auto &n : pandigital_products)
            result += n;
        return result;
    }
}