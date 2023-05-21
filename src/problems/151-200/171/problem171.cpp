//
// Created by Alex Beccaro on 17/05/2023.
//

#include "cmath"
#include "problem171.hpp"


using std::map;
using std::pair;
using std::vector;

namespace problems {
    vector<uint32_t> problem171::squares;

    vector<uint64_t> problem171::powers_ten;

    map<pair<uint32_t, uint32_t>, pair<uint32_t, uint64_t>> problem171::mem;

    pair<uint32_t, uint64_t> problem171::numbers_sum(uint32_t sum, uint32_t digits) {
        // If sum is 0 then there is only one solution with all zeroes
        if (sum == 0)
            return {1, 0};

        // If sum is too big for the number of digits there are no solutions
        if (digits * squares[9] < sum)
            return {0, 0};

        // Check if result is already stored in memory
        pair<uint32_t, uint32_t> key = {sum, digits};
        if (mem.find(key) != mem.end())
            return mem[key];

        // Try setting one digit with any value 0-9 and call the function recursively, summing the results (and the
        // digit if necessary, considering its place)
        uint32_t count = 0;
        uint64_t total = 0;
        for (uint32_t a = 0; a <= 9; a++) {
            if (squares[a] > sum)
                break;

            auto [sub_count, sub_total] = numbers_sum(sum - squares[a], digits - 1);
            total += sub_total;
            if (digits < 10)
                total += a * powers_ten[digits - 1] * sub_count;
            count += sub_count;
        }

        // Store result and return
        mem[key] = {count, total % powers_ten[9]};
        return mem[key];
    }

    uint64_t problem171::solve(uint32_t digits) {
        // reset memory state and precalculate squares and powers of ten for efficiency
        mem = {};

        squares = {};
        uint32_t max_square = floor(sqrt(81 * digits));
        for (uint32_t i = 0; i <= max_square; i++)
            squares.push_back(i * i);

        powers_ten = {1};
        for (uint32_t i = 1; i < 10; i++)
            powers_ten.push_back(powers_ten.back() * 10);

        // for each possible square sum call the dp function and sum the results
        uint64_t result = 0;
        for (const auto& square : squares)
            result += numbers_sum(square, digits).second;

        return result % powers_ten[9];
    }
}