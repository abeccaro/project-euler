//
// Created by Alex Beccaro on 21/01/18.
//

#include "problem68.hpp"
#include "sstream"
#include "algorithm"

using std::vector;
using std::string;
using std::stringstream;

namespace problems {
    bool problem68::is_valid(const vector<uint32_t>& str) {
        uint32_t sum = str[0] + str[1] + str[2];

        return str[3] + str[2] + str[4] == sum &&
               str[5] + str[4] + str[6] == sum &&
               str[7] + str[6] + str[8] == sum &&
               str[9] + str[8] + str[1] == sum &&
               str[0] < str[3] && str[0] < str[5] && str[0] < str[7] && str[0] < str[9];
    }

    string problem68::solve() {
        // representing string (a0, a1, a2),(a3, a2, a4),(a5, a4, a6),(a7, a6, a8),(a9, a8, a1)
        // as a vector {a0, ..., a9}
        // as a0 is the lowest of outer numbers 6 is the maximum value it can have.
        // a1 and a2 must be lower than a0 because they are internal.
        // Further optimisations are not worth.
        vector<uint32_t> str = {6, 5, 4, 10, 9, 8, 7, 3, 2, 1};

        while (true) {
            if (is_valid(str)) {
                stringstream ss;
                ss << str[0] << str[1] << str[2]
                   << str[3] << str[2] << str[4]
                   << str[5] << str[4] << str[6]
                   << str[7] << str[6] << str[8]
                   << str[9] << str[8] << str[1];
                if (ss.str().size() < 17)
                    return ss.str();
            }
            prev_permutation(str.begin(), str.end());
        }
    }
}
