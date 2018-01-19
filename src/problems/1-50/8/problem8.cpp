//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem8.hpp"
#include <input.hpp>

using namespace input;

namespace problems {
/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
    ulong problem8::solve(uint digits) {
        vector<uint> numbers = read_vector<uint>(PROBLEMS_FOLDER + "1-50/8/input.txt");

        ulong maxProduct = numeric_limits<ulong>::min();
        for (ulong i = 0; i <= numbers.size() - digits; i++) {
            ulong product = 1;

            for (uint j = 0; j < digits; j++)
                product *= numbers[i + j];

            if (product > maxProduct)
                maxProduct = product;
        }
        return maxProduct;
    }
}