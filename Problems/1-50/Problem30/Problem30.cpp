//
// Created by Alex Beccaro on 18/12/17.
//

#include <iostream>
#include <cmath>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::digits;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype EXPONENT = 5;

    timer::time_point start = timer::now();

    numtype upper_bound_exp = 1;
    while (upper_bound_exp * pow(9, EXPONENT) > pow(10, upper_bound_exp))
        upper_bound_exp++;
    auto upper_bound = (numtype) pow(9, upper_bound_exp);

    numtype result = 0;
    for (numtype i = 10; i < upper_bound; i++) {
        vector<unsigned int> digs = digits(i);
        numtype sum = 0;

        for(const auto& d : digs)
            sum += (numtype) pow(d, EXPONENT);

        if (sum == i)
            result += i;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The the sum of all the numbers that can be written as the sum of " << EXPONENT
         << "th powers of their digits is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}