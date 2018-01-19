//
// Created by Alex Beccaro on 18/01/18.
//

#include "problem13.hpp"
#include <generics.hpp>
#include <input.hpp>


using namespace input;

using generics::digits;
using boost::multiprecision::uint256_t;

namespace problems {
    vector<uint> problem13::solve(uint d) {
        vector<uint256_t> numbers = read_vector<uint256_t>(PROBLEMS_FOLDER + "1-50/13/input.txt");

        uint256_t sum = 0;
        for (const auto &n : numbers)
            sum += n;

        vector<uint> result = digits(sum);
        result.resize(d);
        return result;
    }
}
