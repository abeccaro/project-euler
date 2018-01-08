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
    const numtype UPPER_BOUND = 28123;

    timer::time_point start = timer::now();

    // get abundants
    vector<numtype> abundants;
    for (numtype i = 1; i < UPPER_BOUND; i++) {
        vector<numtype> divs = divisors(i);
        numtype sum = 0;
        for (numtype div : divs)
            sum += div;
        sum -= i;
        if (sum > i)
            abundants.push_back(i);
    }

    // mark all the numbers obtained by summing 2 abundants
    vector<bool> as_sum_of_abundants(UPPER_BOUND);
    for (int i = 0; i < abundants.size(); i++)
        for (int j = i; j < abundants.size(); j++) {
            numtype sum = abundants[i] + abundants[j];
            if (sum < as_sum_of_abundants.size())
                as_sum_of_abundants[sum] = true;
        }

    // calculate sum of non marked numbers
    numtype result = 0;
    for (int i = 1; i < as_sum_of_abundants.size(); i++)
        if (!as_sum_of_abundants[i])
            result += i;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all the positive integers which cannot be written as the sum of two abundant numbers is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}