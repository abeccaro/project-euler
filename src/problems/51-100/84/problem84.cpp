//
// Created by Alex Beccaro on 25/02/18.
//

#include "vector"
#include "map"
#include "algorithm"
#include "problem84.hpp"

using std::vector;
using std::string;
using std::map;

namespace problems {
    map<uint32_t, float> problem84::init_rolls(uint32_t sides) {
        map<uint32_t, float> rolls;
        float p = 1.0f / (sides * sides);

        for (uint32_t i = 2; i < 2 * sides; i++)
            rolls[i] = 0;

        for (uint32_t i = 1; i <= sides; i++) {
            for (uint32_t j = 1; j <= sides; j++) {
                rolls[i + j] += p;
            }
        }

        return rolls;
    }

    vector<float> problem84::turn_to(uint32_t pos) {
        vector<float> probabilities(40);

        switch (pos) {
            case 30: { // GTJ
                probabilities[10] = 1;
                break;
            }
            case 2: // CC1
            case 17: // CC2
            case 33: { // CC3
                probabilities[0] = 1.0f / 16; // GO
                probabilities[10] = 1.0f / 16; // JAIL
                probabilities[pos] = 14.0f / 16; // other
                break;
            }
            case 7: // CH1
            case 22: // CH2
            case 36: { // CH3
                probabilities[0] = 1.0f / 16; // GO
                probabilities[10] = 1.0f / 16; // JAIL
                probabilities[11] = 1.0f / 16; // C1
                probabilities[24] = 1.0f / 16; // E3
                probabilities[39] = 1.0f / 16; // H2
                probabilities[5] = 1.0f / 16; // R1

                if (pos == 7) {
                    probabilities[15] = 2.0f / 16; // next R (R2)
                    probabilities[12] = 1.0f / 16; // next U (U1)
                } else if (pos == 22) {
                    probabilities[25] = 2.0f / 16; // next R (R3)
                    probabilities[28] = 1.0f / 16; // next U (U2)
                } else {
                    probabilities[5] += 2.0f / 16; // next R (R1)
                    probabilities[12] = 1.0f / 16; // next U (U1)
                }

                // Back 3 squares
                if (pos == 36) {
                    vector<float> p = turn_to(pos - 3);
                    for (uint32_t i = 0; i < probabilities.size(); i++)
                        probabilities[i] += p[i] * 1.0f / 16;
                } else
                    probabilities[pos - 3] = 1.0f / 16;

                probabilities[pos] = 6.0f / 16; // other
                break;
            }
            default: probabilities[pos] = 1;
        }

        return probabilities;
    }

    vector<float> problem84::turn_from(uint32_t pos, const map<uint32_t, float>& rolls) {
        vector<float> probabilities(40);

        // JAIL if third consecutive double
        uint32_t sides = (uint32_t) ((rolls.size() + 1) / 2.0f);
        float three_floats_p = 1.0f / (sides * sides * sides);
        probabilities[10] += three_floats_p;

        // normal rolls with corresponding probability
        for (const auto& roll : rolls) {
            vector<float> results = turn_to((pos + roll.first) % 40);
            for (int j = 0; j < probabilities.size(); j++)
                probabilities[j] += results[j] * roll.second * (1 - three_floats_p);
        }

        return probabilities;
    }

    vector<float> problem84::turn(const vector<float>& probabilities, const map<uint32_t, float>& rolls) {
        vector<float> new_probabilities(probabilities.size());

        for (uint32_t i = 0; i < probabilities.size(); i++) {
            vector<float> p = turn_from(i, rolls);
            for (int j = 0; j < p.size(); j++)
                new_probabilities[j] += p[j] * probabilities[i];
        }

        return new_probabilities;
    }

    string problem84::solve(uint32_t sides) {
        map<uint32_t, float> rolls = init_rolls(sides);

        // starting from first square
        vector<float> probabilities(40);
        probabilities[0] = 1;

        // simulate new turns until probabilities converges
        while (true) {
            vector<float> new_p = turn(probabilities, rolls);
            if (new_p == probabilities)
                break;
            probabilities = new_p;
        }

        string result;
        for (uint32_t i = 0; i < 3; i++) {
            int64_t argMax = std::distance(probabilities.begin(), max_element(probabilities.begin(), probabilities.end()));
            result += argMax == 0 ? "00" : std::to_string(argMax);
            probabilities[argMax] = 0; // remove from next max
        }

        return result;
    }

}