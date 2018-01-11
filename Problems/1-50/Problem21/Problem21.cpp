//
// Created by Alex Beccaro on 17/12/17.
//

#include <iostream>
#include <vector>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::divisors;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 10000;

    timer::time_point start = timer::now();

    vector<numtype> divisors_sums(UPPER_BOUND);
    for (numtype i = 2; i < UPPER_BOUND; i++) {
        vector<numtype> divs = divisors(i);
        for (const auto& div : divs)
            divisors_sums[i] += div;
        divisors_sums[i] -= i;
    }

    numtype result = 0;
    for (numtype i = 2; i < UPPER_BOUND; i++)
        if (divisors_sums[i] < divisors_sums.size() &&
                divisors_sums[i] != i && divisors_sums[divisors_sums[i]] == i)
            result += i;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all amicable numbers under " << UPPER_BOUND << " is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}