//
// Created by Alex Beccaro on 16/05/2023.
//

#include "generics.hpp"
#include "problem170.hpp"
#include "vector"


using generics::digits;
using generics::divisors;
using generics::from_digits;
using generics::gcd;
using std::adjacent_find;
using std::pair;
using std::prev_permutation;
using std::sort;
using std::vector;

namespace problems {
    bool problem170::is_pandigital(vector<uint32_t>& digits) {
        if (digits.size() < 10)
            return false;
        sort(digits.begin(), digits.end());
        return adjacent_find(digits.begin(), digits.end()) == digits.end();
    }

    vector<pair<uint32_t, uint32_t>> problem170::split(const vector<uint32_t>& number_digits) {
        vector<pair<uint32_t, uint32_t>> result = {};
        for (auto it = number_digits.begin() + 1; it != number_digits.end() - 1; it++) {
            auto p1 = from_digits<uint32_t>({number_digits.begin(), it});
            auto p2 = from_digits<uint32_t>({it, number_digits.end()});
            result.emplace_back(p1, p2);
        }
        return result;
    }

    uint64_t problem170::solve() {
        vector<uint32_t> number_digits = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

        // Cycle from the highest number so as soon as we find a solution we know it's the greater.
        // If we get to 0xxxxxxxxx there is no solution.
        while (number_digits[0] != 0) {
            /*
             * Divide the combined product in its single products. We can only look at couples of products by reasoning
             * on the common factor:
             * - as in each product the result has d or d-1 digits where d is the sum of digits of
             * the factors, the common factor must have 1 or 2 digits, otherwise the concatenation of the products will
             * have more than 10 digits
             * - for 1-digit common factors there will be only one product with d digits, all others will have d-1,
             * otherwise the concatenated product won't have 10 digits. In this scenario we can concatenate all the
             * d-1 digit products in one (and their factors in the same order) to find another valid "solution" with the
             * same concatenated final product. This way by looking only at the 2 products combinations we are
             * considering the same concatenated products as we'll find them from their 2-product solution
             */
            vector<pair<uint32_t, uint32_t>> product_pairs = split(number_digits);

            for (const auto& [p1, p2] : product_pairs) {
                // The possible common factors are the shared divisors
                auto common_factors = divisors(gcd(p1, p2));

                // For each one calculate the factors f1 and f2 that validate the multiplications and check if the
                // concatenated number common_factor + f1 + f2 is pandigital
                for (const auto& common_factor : common_factors) {

                    vector<uint32_t> input_digits = digits(common_factor);

                    vector<uint32_t> f1 = digits(p1 / common_factor);
                    input_digits.insert(input_digits.end(), f1.begin(), f1.end());
                    vector<uint32_t> f2 = digits(p2 / common_factor);
                    input_digits.insert(input_digits.end(), f2.begin(), f2.end());

                    if (is_pandigital(input_digits))
                        return from_digits<uint64_t>(number_digits);
                }
            }

            prev_permutation(number_digits.begin(), number_digits.end());
        }

        // no solution found
        return 0;
    }
}