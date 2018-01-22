//
// Created by Alex Beccaro on 22/01/18.
//

#include "problem74.hpp"
#include <generics.hpp>

using generics::factorial;
using generics::digits;

namespace problems {
    uint problem74::chain_length(uint n, vector<uint>& memory,
                                 const vector<uint>& factorials, vector<ulong>& chain) {
        // if already in memory return length
        if (n < memory.size() && memory[n] != 0)
            return memory[n];

        // if already found in current chain we got a period:
        // setting all period numbers length and returning 0 (used for non period numbers)
        auto i = find(chain.begin(), chain.end(), n);
        if (i != chain.end()) {
            uint period_length = distance(i, chain.end() - 1) + 1;
            for (; i != chain.end(); i++)
                if (*i < memory.size())
                    memory[*i] = period_length;

            return 0;
        }

        // calculate next number in chain
        ulong sum = 0;
        vector<uint> digs = digits(n);
        for (const auto& d : digs)
            sum += factorials[d];

        // add current number to chain
        chain.push_back(n);
        // recursive call to next number
        uint length = 1 + chain_length(sum, memory, factorials, chain);
        // memoization for non period number (recursively)
        if (n < memory.size() && memory[n] == 0)
            memory[n] = length;
        // returning final length
        return length;
    }

    uint problem74::solve(uint ub) {
        vector<uint> f(10);
        vector<uint> memory(ub);
        vector<ulong> chain;
        uint result = 0;

        // pre-calculating factorials for digits
        for (uint i = 0; i < 10; i++)
            f[i] = factorial(i);

        // calculating chein lengths
        for (uint i = 0; i < ub; i++) {
            chain.clear();
            if (chain_length(i, memory, f, chain) == 60)
                result++;
        }

        return result;
    }
}
