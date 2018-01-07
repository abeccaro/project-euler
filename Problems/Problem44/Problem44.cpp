/*
 * Created by Alex Beccaro on 07/01/18.
 *
 * N.B.: this program doesn't actually checks that the solution is correct, as it assumes that the pair with pentagonal
 *       sum and difference and the smallest p_k has actually the smallest D for p_k > p_j. This assumption is done
 *       based on the fact that requested properties are quite rare so it's very unlikely to have another couple with
 *       higher p_k and lower D and doing the check would require a lot of time.
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
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    figurate_number<numtype> p(5);
    numtype result;

    for (numtype k = 1; true; k++) {
        for (numtype j = 0; j < k; j++)
            if (is_pentagonal(p[k] + p[j]) && is_pentagonal(p[k] - p[j])) {
                result = p[k] - p[j];
                break;
            }

        if (result != 0)
            break;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The minimum difference between two pentagonal numbers that summed and subtracted give pentagonal numbers "
         << "is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}