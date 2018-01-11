//
// Created by Alex Beccaro on 17/12/17.
//

#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Returns the number of days in month/year
 * @param year The year
 * @param month The month
 * @return The number of days
 */
numtype days_in_month(unsigned int year, unsigned int month) {
    switch (month) {
        case 2: return year % 4 == 0 ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        default: return 31;
    }
}

/**
 * Counts Sundays that fell on the first of a month given a vector of number of days in each month and how many days
 * passed from last Sunday
 * @param days_in_months The vector with number of days of months
 * @param passed_from_sunday The number of days passed from last Sunday
 * @return The number of Sundays that fell on the first of the month
 */
numtype count_sundays(const vector<numtype>& days_in_months, numtype passed_from_sunday) {
    numtype sundays = 0;
    for (numtype days_in_month : days_in_months) {
        if(passed_from_sunday == 0)
            sundays++;

        passed_from_sunday = (days_in_month + passed_from_sunday) % 7;
    }

    return sundays;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    vector<numtype> days_in_months;
    days_in_months.reserve(1200);

    for (unsigned int y = 1901; y <= 2000; y++)
        for (unsigned int m = 1; m <= 12; m++)
            days_in_months.push_back(days_in_month(y, m));

    numtype result = count_sundays(days_in_months, 2); // 1 Jan 1901 was a Tuesday

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The number of Sundays fallen on the first of the month during the twentieth century is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}