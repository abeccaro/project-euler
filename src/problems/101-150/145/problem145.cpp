//
// Created by Alex Beccaro on 16/01/2020.
//

#include "problem145.hpp"
#include <generics.hpp>


using generics::int_pow;


namespace problems {

    uint32_t problem145::solve(uint32_t ub_exp) {
        uint32_t res = 0;

        for (uint32_t e = 2; e <= ub_exp; e++) {
            uint32_t mod = e % 4;
            switch(mod) {
                case 0:
                case 2: {
                    res += 20 * int_pow(30u, e / 2 - 1);
                    break;
                }
                case 3: {
                    res += int_pow(25u, e / 4) * int_pow(20u, e / 4 + 1) * 5;
                    break;
                }
                case 1:
                default: break;
            }
        }

        return res;
    }

}