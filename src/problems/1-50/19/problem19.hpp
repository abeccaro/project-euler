//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM19_HPP
#define PROJECT_EULER_PROBLEM19_HPP

#include <cstdint>
#include <vector>

namespace problems {
    class problem19 {
    private:
        /**
         * Returns the number of days in month/year
         * @param year The year
         * @param month The month
         * @return The number of days
         */
        static uint32_t days_in_month(uint32_t year, uint32_t month);

        /**
         * Counts Sundays that fell on the first of a month given a vector of number of days in each month and how many days
         * passed from last Sunday
         * @param days_in_months The vector with number of days of months
         * @param passed_from_sunday The number of days passed from last Sunday
         * @return The number of Sundays that fell on the first of the month
         */
        static uint32_t count_sundays(const std::vector<uint32_t>& days_in_months, uint32_t passed_from_sunday);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM19_HPP
