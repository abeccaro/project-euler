//
// Created by Alex Beccaro on 11/01/18.
//

#include "problem61.hpp"
#include <series/figurate_number.hpp>

using std::vector;
using std::map;
using std::pair;

using series::figurate_number;

namespace problems {
    bool problem61::find_cycle(const map<couple, vector<couple>> &m,
                               const pair<couple, vector<couple>> &entry,
                               vector<couple> &sol, uint32_t length) {
        uint32_t n = entry.first.first; // number of sides of figure

        if (count_if(sol.begin(), sol.end(), [n](couple p) { return p.first == n; }) > 0)
            return false;

        sol.emplace_back(n, entry.first.second);
        if (sol.size() == length) {
            if (sol.front().second / 100 == sol.back().second % 100)
                return true;
            else {
                sol.pop_back();
                return false;
            }
        }

        for (const auto &key : entry.second) {
            pair<couple, vector<couple>> sub_entry = *m.find(key);
            if (find_cycle(m, sub_entry, sol, length))
                return true;
        }

        sol.pop_back();
        return false;
    }


    uint32_t problem61::solve(uint32_t size) {
        map<couple, vector<couple>> m; // number -> list of numbers that can follow key in a cycle

        for (uint32_t i = 3; i < 3 + size; i++) {
            // generate figurate numbers with 4 digits
            figurate_number<uint32_t> s(i);
            vector<uint32_t> numbers = s.get_while([](uint32_t n) { return n < 10000; },
                                                  [](uint32_t n) { return n >= 1000; });

            // for each number generated update already present entries and create new one
            for (const auto &n : numbers) {
                couple c(i, n);
                vector<couple> v;

                // for each entry already in the map with different sides count
                for (auto &entry : m)
                    if (entry.first.first != i) {
                        // if cyclic continuation of already present entry then add to its list
                        if (entry.first.second % 100 == n / 100)
                            entry.second.push_back(c);

                        // if entry starting number is cyclic continuation of n then add it to its list
                        if (entry.first.second / 100 == n % 100)
                            v.push_back(entry.first);
                    }

                // add new entry
                m[c] = v;
            }
        }

        uint32_t result = 0;
        // for each entry test if a cycle of N is found starting from that entry
        for (const auto &entry : m) {
            vector<couple> solution;
            if (find_cycle(m, entry, solution, size)) {
                for (const auto &p : solution)
                    result += p.second;
                break;
            }
        }
        return result;
    }
}