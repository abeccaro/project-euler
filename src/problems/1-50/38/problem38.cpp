//
// Created by Alex Beccaro on 04/01/18.
//

#include "problem38.hpp"
#include "generics.hpp"

using std::vector;
using generics::digits;
using generics::from_digits;

namespace problems {
    uint64_t problem38::solve() {
        uint64_t max = 0;
        const vector<uint32_t> all_digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (uint32_t i = 1; i < 10000; i++) {
            vector<uint32_t> product_digits;

            for (uint32_t j = 1; product_digits.size() < 9; j++) {
                vector<uint32_t> partial_product = digits(i * j);

                product_digits.insert(product_digits.end(), partial_product.begin(), partial_product.end());
            }

            uint64_t product = from_digits<uint64_t>(product_digits);
            sort(product_digits.begin(), product_digits.end());

            if (product_digits == all_digits && product > max)
                max = product;
        }
        return max;
    }
}