//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem17.hpp"

namespace problems {
    uint problem17::letters(uint n) {
        switch (n) {
            case 0: return 0;
            case 1: return 3;
            case 2: return 3;
            case 3: return 5;
            case 4: return 4;
            case 5: return 4;
            case 6: return 3;
            case 7: return 5;
            case 8: return 5;
            case 9: return 4;
            case 10: return 3;
            case 11: return 6;
            case 12: return 6;
            case 13: return 8;
            case 14: return 8;
            case 15: return 7;
            case 16: return 7;
            case 17: return 9;
            case 18: return 8;
            case 19: return 8;
            case 20: return 6;
            case 30: return 6;
            case 40: return 5;
            case 50: return 5;
            case 60: return 5;
            case 70: return 7;
            case 80: return 6;
            case 90: return 6;
            case 1000: return 11;
            default: {
                uint sum = 0;

                uint x = n % 100;
                if (x < 20 || x % 10 == 0)
                    sum += letters(x);
                else {
                    uint units = x % 10;
                    sum += letters(units);
                    sum += letters(x - units);
                }

                uint y = (n / 100);
                sum += letters(y) + (y == 0 ? 0 : (x == 0 ? 7 : 10));

                return sum;
            }
        }
    }

    uint problem17::solve(uint ub) {
        uint sum = 0;
        for (uint i = 1; i <= ub; i++)
            sum += letters(i);
        return sum;
    }
}