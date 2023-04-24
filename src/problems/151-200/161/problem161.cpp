//
// Created by Alex Beccaro on 23/04/2023.
//

#include "iostream"
#include "problem161.hpp"

using std::vector;
using std::unordered_map;
using std::pair;
using std::min;
using std::max;

namespace problems {
    problem161::grid_state::grid_state(uint32_t rows, uint32_t cols): bitmask(rows * cols, false), first_empty(0), row_size(min(rows, cols)) {}

    problem161::grid_state::grid_state(const grid_state& g) = default;

    std::optional<problem161::grid_state> problem161::grid_state::add_piece(uint32_t offset1, uint32_t offset2) const {
        if (first_empty + std::max(offset1, offset2) >= bitmask.size() || bitmask[first_empty + offset1] || bitmask[first_empty + offset2])
            return {};
        if (offset1 == row_size - 1 && first_empty % row_size == 0)
            return {};
        if ((offset1 == 1 || offset2 == row_size + 1) && first_empty % row_size == row_size - 1)
            return {};
        if (offset2 == 2 && first_empty % row_size >= row_size - 2)
            return {};

        grid_state new_state(*this);

        new_state.bitmask[first_empty] = true;
        new_state.bitmask[first_empty + offset1] = true;
        new_state.bitmask[first_empty + offset2] = true;

        auto new_first_empty = std::find_if(new_state.bitmask.begin() + first_empty, new_state.bitmask.end(), [](bool filled){ return !filled; });
        new_state.first_empty = new_first_empty == new_state.bitmask.end() ? -1 : new_first_empty - new_state.bitmask.begin();

        return new_state;
    }

    vector<problem161::grid_state> problem161::grid_state::add_pieces() const {
        vector<grid_state> result;

        vector<pair<uint32_t, uint32_t>> pieces_offsets = {
                // X X
                // X O
                {1, row_size},
                // X X
                // O X
                {1, row_size + 1},

                // X O
                // X X
                {row_size, row_size + 1},
                // O X
                // X X
                // point is the first row second column
                {row_size - 1, row_size},
                // X
                // X
                // X
                {row_size, row_size * 2},
                // X X X
                {1, 2},
        };

        for (const auto& offsets : pieces_offsets) {
            auto new_state = add_piece(offsets.first, offsets.second);
            if (new_state.has_value())
                result.push_back(new_state.value());
        }

        return result;
    }

    unordered_map<vector<bool>, uint64_t> problem161::mem;

    uint64_t problem161::count(const grid_state& g) {
        if (mem.contains(g.bitmask))
            return mem[g.bitmask];

        auto results = g.add_pieces();
        uint64_t total = 0;
        for (const auto& res : results)
            total += count(res);

        mem[g.bitmask] = total;

        return mem[g.bitmask];
    }

    uint64_t problem161::solve(uint64_t n, uint64_t m) {
        if (n % 3 == 1 && m % 3 == 1)
            return 0;

        // 1 by n => 1 (assuming n = 3k from previous check)
        if (min(n, m) == 1)
            return 1;

        // 2 by n => 4*f(2, n-3) - f(2, n-6) (assuming n = 3k from previous check)
        if (min(n, m) == 2) {
            uint32_t maximum = max(n, m) / 3;

            uint32_t res = 1;
            for (uint32_t prev = 1, i = 0; i < maximum; i++) {
                uint32_t tmp = res;
                res = 4 * res - prev;
                prev = tmp;
            }
            return res;
        }

        // complex case, count solutions using memoization
        vector<bool> all_filled(n*m, true);
        mem = {{all_filled, 1}};
        grid_state g(n, m);
        return count(g);
    }
}