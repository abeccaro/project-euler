//
// Created by Alex Beccaro on 04/12/18.
//

#include "problem104.hpp"
#include "generics.hpp"

using std::vector;

using generics::digits;

namespace problems {
    uint32_t problem104::solve() {
        double log = log10((1 + std::sqrt(5)) / 2); // log_10(phi)
        double c = log10(5) / 2;
        uint64_t n1 = 1, n2 = 1;

        vector<uint32_t> d = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (uint32_t i = 3; i != 0; i++) {
            // last digits
            uint64_t temp = (n1 + n2) % 1000000000;
            n2 = n1;
            n1 = temp;

            vector<uint32_t> digs = digits(n1);
            std::sort(digs.begin(), digs.end());

            if (digs == d) { // if last digits are 1-9
                // first digits (using log formula on approximation)
                double x = i * log - c;
                double digits_count;

                uint64_t first_digits = (uint64_t) floor(pow(10, modf(x, &digits_count)) * 100000000);
                //digits_count++;

                digs = digits(first_digits);
                std::sort(digs.begin(), digs.end());

                if (digs == d)
                    return i;
            }
        }

        return 0;
    }
}