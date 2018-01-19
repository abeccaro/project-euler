//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem19.hpp"

namespace problems {
    uint problem19::days_in_month(unsigned int year, unsigned int month) {
        switch (month) {
            case 2: return year % 4 == 0 ? 29 : 28; // safe for 1901-2000
            case 4:
            case 6:
            case 9:
            case 11: return 30;
            default: return 31;
        }
    }

    uint problem19::count_sundays(const vector<uint>& days_in_months, uint passed_from_sunday) {
        uint sundays = 0;
        for (uint days_in_month : days_in_months) {
            if (passed_from_sunday == 0)
                sundays++;

            passed_from_sunday = (days_in_month + passed_from_sunday) % 7;
        }

        return sundays;
    }

    uint problem19::solve() {
        vector<uint> days_in_months;
        days_in_months.reserve(1200);

        for (uint y = 1901; y <= 2000; y++)
            for (uint m = 1; m <= 12; m++)
                days_in_months.push_back(days_in_month(y, m));

        return count_sundays(days_in_months, 2); // 1 Jan 1901 was a Tuesday
    }
}