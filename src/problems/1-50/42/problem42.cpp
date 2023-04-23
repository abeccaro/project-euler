//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem42.hpp"
#include "input.hpp"

using std::vector;
using std::string;
using input::read_vector;
using input::problems_folder;

namespace problems {
    uint32_t problem42::solve() {
        uint32_t result = 0;
        vector<string> words = read_vector<string>(problems_folder + "1-50/42/input.txt");

        for (const auto &word : words) {
            uint32_t score = 0;
            for (const auto &letter : word)
                score += letter - 'A' + 1;

            // x is triangular if 8x + 1 is a square
            uint32_t n = 8 * score + 1;
            auto root = (uint32_t) sqrt(n);
            if (root * root == n)
                result++;
        }

        return result;
    }
}