//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include <vector>
#include "series/fibonacci.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using series::fibonacci;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 4000000;

    timer::time_point start = timer::now();

    fibonacci<numtype> fib;
    auto lessThanUB = [UPPER_BOUND](numtype n) {return n <= UPPER_BOUND;};
    auto isEven = [](numtype n) {return n % 2 == 0;};

    vector<numtype> fibonacci = fib.get_while(lessThanUB, isEven);

    numtype sum = 0;
    for (const numtype &f : fibonacci)
        sum += f;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all even fibonacci numbers up to 4 million is " << sum << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}