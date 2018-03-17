//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem22.hpp"
#include <input.hpp>

using namespace input;

namespace problems {
    uint problem22::solve() {
        std::vector<std::string> names = read_vector<std::string>(problems_folder + "1-50/22/input.txt");
        sort(names.begin(), names.end());

        uint sum = 0;
        for (uint i = 0; i < names.size(); i++) {
            uint score = 0;
            for (const auto &letter : names[i])
                score += letter - 'A' + 1;
            sum += score * (i + 1);
        }
        return sum;
    }
}