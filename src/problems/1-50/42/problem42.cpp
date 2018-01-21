//
// Created by Alex Beccaro on 07/01/18.
//

#include "problem42.hpp"
#include <input.hpp>

using namespace input;

namespace problems {
    uint problem42::solve() {
        uint result = 0;
        vector<string> words = read_vector<string>(PROBLEMS_FOLDER + "1-50/42/input.txt");

        for (const auto &word : words) {
            uint score = 0;
            for (const auto &letter : word)
                score += letter - 'A' + 1;

            // x is triangular if 8x + 1 is a square
            uint n = 8 * score + 1;
            auto root = (uint) sqrt(n);
            if (root * root == n)
                result++;
        }

        return result;
    }
}