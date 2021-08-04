//
// Created by Alex Beccaro on 03/08/2021.
//

#include "problem151.hpp"
#include "generics.hpp"
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using generics::digits;
using std::accumulate;


namespace problems {

    double problem151::solve() {
        // states are represented as a number where each digit, in order, represents the quantity of A2, A3, A4 and A5
        // sheets in the envelope
        unordered_map<uint32_t, double> p = {{1111, 1}};
        vector<uint32_t> current = {1111};
        unordered_set<uint32_t> next;

        for (uint32_t batch = 2; batch <= 16; batch++) {
            for (const auto& state : current) {
                vector<uint32_t> d = digits(state);
                uint32_t total = accumulate(d.begin(), d.end(), 0u); // total number of sheets in the envelope

                // each mask represents a possible format (A2, A3, A4 or A5)
                for (uint32_t mask = 1000; mask > 0; mask /= 10) {
                    uint32_t n = state % (mask * 10) / mask; // number of sheets of the mask format
                    if (n == 0)
                        continue;

                    // apply cuts to generate the new state and add it to the set for next batch
                    uint32_t to_add = 0;
                    for (uint32_t i = 1; i < mask; i *= 10)
                        to_add += i;
                    uint32_t new_state = state - mask + to_add;
                    next.insert(new_state);

                    // update probability of new state
                    double p_next = p[state] * n / total;
                    if (p.find(new_state) != p.end())
                        p[new_state] += p_next;
                    else
                        p.insert({new_state, p_next});
                }
            }

            current.assign(next.begin(), next.end());
            next.clear();
        }

        return p[1000] + p[100] + p[10];
    }
}