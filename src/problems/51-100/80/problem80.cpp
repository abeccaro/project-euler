//
// Created by Alex Beccaro on 18/12/17.
//

#include <boost/multiprecision/cpp_dec_float.hpp>
#include "problem80.hpp"
#include <iostream>

using boost::multiprecision::cpp_dec_float_100;
using std::string;

namespace problems {
    uint problem80::solve(uint ub) {
        uint sum = 0;
        for (uint i = 2; i <= ub; i++) {
            cpp_dec_float_100 n(i);
            n = sqrt(n);
            if (n == (uint) n)
                continue;

            string s = n.str().substr(0, 101); // 100 digits and '.'
            s.erase(s.find('.'), 1);

            for (const auto& c : s)
                sum += c - '0';
        }
        return sum;
    }
}