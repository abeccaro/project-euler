//
// Created by Alex Beccaro on 04/01/18.
//

#include "problem38.hpp"
#include <generics.hpp>

using generics::digits;
using generics::from_digits;

using uint = unsigned int;

namespace problems {
    ulong problem38::solve() {
        ulong max = 0;
        const std::vector<uint> all_digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (uint i = 1; i < 10000; i++) {
            std::vector<uint> product_digits;

            for (uint j = 1; product_digits.size() < 9; j++) {
                std::vector<uint> partial_product = digits(i * j);

                product_digits.insert(product_digits.end(), partial_product.begin(), partial_product.end());
            }

            ulong product = from_digits<ulong>(product_digits);
            sort(product_digits.begin(), product_digits.end());

            if (product_digits == all_digits && product > max)
                max = product;
        }
        return max;
    }
}