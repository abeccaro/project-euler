//
// Created by Alex Beccaro on 18/01/18.
//

#include "problem13.hpp"
#include <generics.hpp>
#include <input.hpp>

using std::vector;
using input::read_vector;
using input::problems_folder;
using generics::digits;
using boost::multiprecision::uint256_t;

namespace problems {
    vector<uint32_t> problem13::solve(uint32_t d) {
        vector<uint256_t> numbers = read_vector<uint256_t>(problems_folder + "1-50/13/input.txt");

        uint256_t sum = 0;
        for (const auto &n : numbers)
            sum += n;

        vector<uint32_t> result = digits(sum);
        result.resize(d);
        return result;
    }
}
