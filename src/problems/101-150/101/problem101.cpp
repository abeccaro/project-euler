//
// Created by Alex Beccaro on 21/03/18.
//

#include <vector>
#include "problem101.hpp"

using std::vector;

namespace problems {
    int64_t problem101::default_fun(int32_t x) {
        int64_t power = 1;
        int64_t y = 1;
        int32_t sign = -1;

        for (uint32_t i = 1; i <= 10; i++) {
            power *= x;
            y += sign * power;
            sign = -sign;
        }

        return y;
    }

    int64_t problem101::lagrange_interpolate_next(const vector<int64_t>& y) {
        int64_t x = y.size();

        if (x == 1)
            return y.back();

        int64_t result = 0;

        for (int32_t i = 1; i <= x; i++) {
            int64_t num = y[i - 1];
            int64_t den = 1;

            for (int32_t j = 1; j <= x; j++) {
                if (j == i)
                    continue;

                num *= x + 1 - j;
                den *= i - j;
            }

            result += num / den;
        }

        return result;
    }

    int64_t problem101::solve(const std::function<int64_t (int32_t)>& fun) {
        int64_t result = 0;
        vector<int64_t> fun_res(1, fun(1));

        for (int32_t i = 2; ; i++) {
            int64_t y = lagrange_interpolate_next(fun_res);
            fun_res.push_back(fun(i));

            if (y == fun_res.back())
                break;

            result += y;
        }

        return result;
    }
}