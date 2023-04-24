//
// Created by Alex Beccaro on 23/04/2023.
//

#include "generics.hpp"
#include "problem162.hpp"


using generics::combinations;
using generics::int_pow;
using generics::to_base;
using std::ostringstream;
using std::string;
using std::vector;

namespace problems {
    uint64_t problem162::count(uint64_t n) {
        std::vector<uint64_t> indices(n);
        std::iota(indices.begin(), indices.end(), 0); // Fill with 0, 1, ..., n.
        vector<vector<uint64_t>> position_combinations = combinations(indices, 3);

        uint64_t result = 0;
        for (const auto& positions: position_combinations) {
            uint64_t factor = positions[0] == 0 ? 4 : 6;
            result += factor *
                    int_pow(13ull, positions[0]) *
                    int_pow(14ull, positions[1] - positions[0] - 1) *
                    int_pow(15ull, positions[2] - positions[1] - 1) *
                    int_pow(16ull, n - positions[2] - 1);
        }

        return result;
    }

    std::string problem162::to_hexadecimal_string(uint64_t n) {
        ostringstream oss;
        for (const auto& digit : to_base(n, 16)) {
            switch (digit) {
                case 10: oss << "A"; break;
                case 11: oss << "B"; break;
                case 12: oss << "C"; break;
                case 13: oss << "D"; break;
                case 14: oss << "E"; break;
                case 15: oss << "F"; break;
                default: oss << digit; break;
            }
        }
        return oss.str();
    }

    string problem162::solve(uint32_t n) {
        if (n < 3)
            return "0";

        uint64_t result = 4;
        for (uint64_t i = 4; i <= n; i++)
            result += count(i);
        return to_hexadecimal_string(result);
    }
}