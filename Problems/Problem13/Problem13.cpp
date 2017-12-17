//
// Created by Alex Beccaro on 15/12/17.
//

#include <iostream>
#include <generics.hpp>
#include "input.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace input;
using generics::digits;

using numtype = cpp_int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const unsigned long DIGITS = 10;

    timer::time_point start = timer::now();

    vector<numtype> numbers = read_vector<numtype>(project_path + "Problems/Problem13/input.txt");

    numtype sum = 0;
    for (numtype n : numbers)
        sum += n;

    vector<unsigned short> first_digits = digits(sum);
    first_digits.resize(DIGITS);

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The first " << DIGITS << " digits of the sum are ";
    for (int i = 0; i < DIGITS; i++)
        cout << first_digits[i];
    cout << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}