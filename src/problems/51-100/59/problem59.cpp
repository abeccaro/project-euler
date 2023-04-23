//
// Created by Alex Beccaro on 11/01/18.
//

#include "problem59.hpp"
#include "input.hpp"

using std::vector;
using std::string;

using input::read_vector;
using input::problems_folder;

namespace problems {
    uint32_t problem59::solve() {
        vector<uint32_t> words = read_vector<uint32_t>(problems_folder + "/51-100/59/input.txt");
        string pw = "___";
        uint32_t result, max_letters = 0;

        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            pw[0] = c1;
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                pw[1] = c2;
                for (char c3 = 'a'; c3 <= 'z'; c3++) {
                    pw[2] = c3;

                    uint32_t letters = 0, sum = 0;
                    for (uint32_t i = 0; i < words.size(); i++) {
                        char c = pw[i % 3] ^ words[i];
                        if (c >= 'a' && c <= 'z')
                            letters++;
                        sum += c;
                    }

                    if (letters > max_letters) {
                        result = sum;
                        max_letters = letters;
                    }
                }
            }
        }

        return result;
    }
}