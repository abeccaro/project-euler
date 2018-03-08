//
// Created by Alex Beccaro on 07/03/18.
//

#include "problem95.hpp"

namespace problems {
    uint problem95::chain_length(uint n, vector<uint>& memory, const vector<uint>& div_sums, vector<uint>& chain) {
        // if n too big -> no chain
        if (n >= memory.size())
            return 1;

        // if already in memory return length
        if (memory[n] != 0)
            return memory[n];

        // if chain closed update memory values and return length
        auto i = find(chain.begin(), chain.end(), n);
        if (i != chain.end()) {
            // real chain length
            uint period_length = distance(i, chain.end());

            // set memory values for all entries in chain vector
            for (auto j = chain.begin(); j != chain.end(); j++)
                if (j < i)
                    memory[*j] = 1;
                else
                    memory[*j] = period_length;

            return period_length;
        }

        // recursive call
        chain.push_back(n);
        uint l = chain_length(div_sums[n], memory, div_sums, chain);
        // if no chain found (even not including n) then save to memory
        if (l == 1)
            memory[n] = l;

        return memory[n];
    }

    uint problem95::solve(uint ub) {
        vector<uint> mem(ub + 1), chain;
        uint max_length = 0;
        uint result = 0;

        // calculate efficiently divisor sums with sieve
        vector<uint> div_sums(ub + 1, 1);
        div_sums[0] = 0;
        div_sums[1] = 0;
        for (uint i = 2; i <= ub/2; i++)
            for (uint j = i + i; j <= ub; j += i)
                div_sums[j] += i;

        // calculate chain lengths and storing result
        mem[0] = 1;
        for (uint i = 1; i <= ub; i++) {
            chain.clear();
            uint len = chain_length(i, mem, div_sums, chain);

            if (len > max_length) {
                max_length = len;
                result = chain.size() == 0 ? i : *std::min_element(chain.begin(), chain.end());
            }
        }

        return result;
    }
}