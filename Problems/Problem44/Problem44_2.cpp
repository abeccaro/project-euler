/*
 * Created by Alex Beccaro on 07/01/18.
 *
 * N.B.: other version based on project euler forum post on this problem (https://projecteuler.net/thread=44#3218).
 *       This version allows to find a solution that is sure to be correct.
 *       Explanation can be found following the post link.
 */

#include <iostream>
#include <series/figurate_number.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using series::figurate_number;

using numtype = unsigned int;

/**
 * Checks if given number is pentagonal
 * @param n The number to check
 * @return True if n is pentagonal, false otherwise
 */
bool is_pentagonal(numtype n) {
    auto x = (sqrt(24 * n + 1) + 1) / 6;

    return (numtype) x == x;
}

/**
 * Checks if given number is the double of a pentagonal number
 * @param n The number to check
 * @return True if n is the double of a pentagonal number, false otherwise
 */
bool is_double_pentagonal(numtype n) {
    if (n % 2 != 0)
        return false;

    return is_pentagonal(n / 2);
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    figurate_number<numtype> p(5);
    numtype result = 0;

    for (numtype m = 1; result == 0; m++)
        for (numtype k = 0; k < m; k++)
            if (is_double_pentagonal(p[m] + p[k]) && is_double_pentagonal(p[m] - p[k]))
                result = p[k];

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The minimum difference between two pentagonal numbers that summed and subtracted give pentagonal numbers "
         << "is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}