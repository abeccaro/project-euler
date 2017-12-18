//
// Created by Alex Beccaro on 18/12/17.
//

#include <iostream>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype DIMENSION = 1001;

    timer::time_point start = timer::now();

    numtype result = 1;
    for (numtype i = 3; i <= DIMENSION; i += 2)
        for (numtype j = 0; j < 4; j++) // for each diagonal starting from top-right anticlockwise
            result += i * i - j * (i - 1);

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of the numbers on the diagonals in a " << DIMENSION << " by " << DIMENSION << " spiral is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}