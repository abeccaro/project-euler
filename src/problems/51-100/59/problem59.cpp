//
// Created by Alex Beccaro on 11/01/18.
//

#include "problem59.hpp"
#include <input.hpp>

using namespace input;

namespace problems {
    uint problem59::solve() {
        std::vector<uint> words = read_vector<uint>(problems_folder + "/51-100/59/input.txt");
        std::string pw = "___";
        uint result, max_letters = 0;

        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            pw[0] = c1;
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                pw[1] = c2;
                for (char c3 = 'a'; c3 <= 'z'; c3++) {
                    pw[2] = c3;

                    uint letters = 0, sum = 0;
                    for (uint i = 0; i < words.size(); i++) {
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