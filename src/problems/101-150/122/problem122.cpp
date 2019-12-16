//
// Created by Alex Beccaro on 21/01/2019.
//

#include "problem122.hpp"
#include <algorithm>


using std::vector;
using std::min;


namespace problems {

    /*
     * Implemented as BFS where children are chains that starts wth parent and add as last element parent.back + x
     * where x is any parent element.
     * The last element is always used to reduce search space as star addition chains have the same result as normal
     * addition chains for n < 12509. If ub (m.size) is >= 12509 the result might be wrong.
     */
    vector<uint32_t> problem122::addition_chain(uint32_t ub) {
        vector<uint32_t> l(ub, ub - 1);
        vector<bool> explored(ub, false);
        vector<vector<uint32_t>> current, frontier;

        current.emplace_back(1, 1);
        uint32_t depth = 0, count = 0;

        while (count < ub) {
            // mark current chains as explored
            for (const auto& c : current) {
                uint32_t n = c.back();
                if (!explored[n - 1]) {
                    explored[n - 1] = true;
                    count++;
                }
            }

            // looping through current chains updating results and generating frontier
            for (const auto& c : current) {
                uint32_t n = c.back();
                l[n - 1] = min(l[n - 1], depth);

                for (const auto& x : c) {
                    uint32_t y = n + x;
                    if (y <= ub && !explored[y-1]) {
                        vector<uint32_t> new_chain(c);
                        new_chain.push_back(y);
                        frontier.push_back(new_chain);
                    }
                }
            }

            // preparing for new iteration
            current = frontier;
            frontier = {};
            depth++;
        }

        return l;
    }

    uint32_t problem122::solve(uint32_t ub) {
        vector<uint32_t> m = addition_chain(ub);

        uint32_t res = 0;
        for (const auto& l : m)
            res += l;

        return res;
    }

}