//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem8.hpp"
#include "input.hpp"

using std::vector;
using input::read_vector;
using input::problems_folder;

namespace problems {
    uint64_t problem8::solve(uint32_t digits) {
        vector<uint32_t> numbers = read_vector<uint32_t>(problems_folder + "1-50/8/input.txt");

        uint64_t maxProduct = std::numeric_limits<uint64_t>::min();
        for (uint64_t i = 0; i <= numbers.size() - digits; i++) {
            uint64_t product = 1;

            for (uint32_t j = 0; j < digits; j++)
                product *= numbers[i + j];

            if (product > maxProduct)
                maxProduct = product;
        }
        return maxProduct;
    }
}