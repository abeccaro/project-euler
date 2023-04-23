//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem22.hpp"
#include "input.hpp"

using std::vector;
using std::string;
using input::read_vector;
using input::problems_folder;

namespace problems {
    uint32_t problem22::solve() {
        vector<string> names = read_vector<string>(problems_folder + "1-50/22/input.txt");
        sort(names.begin(), names.end());

        uint32_t sum = 0;
        for (uint32_t i = 0; i < names.size(); i++) {
            uint32_t score = 0;
            for (const auto &letter : names[i])
                score += letter - 'A' + 1;
            sum += score * (i + 1);
        }
        return sum;
    }
}