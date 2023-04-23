//
// Created by Alex Beccaro on 18/12/17.
//

#include "boost/multiprecision/cpp_dec_float.hpp"
#include "problem80.hpp"
#include "iostream"

using boost::multiprecision::cpp_dec_float_100;
using std::string;

namespace problems {
    uint32_t problem80::solve(uint32_t ub) {
        uint32_t sum = 0;
        for (uint32_t i = 2; i <= ub; i++) {
            cpp_dec_float_100 n(i);
            n = sqrt(n);
            if (abs(n - (uint32_t) n) < std::numeric_limits<cpp_dec_float_100>::epsilon())
                continue;

            string s = n.str().substr(0, 101); // 100 digits and '.'
            s.erase(s.find('.'), 1);

            for (const auto& c : s)
                sum += c - '0';
        }
        return sum;
    }
}