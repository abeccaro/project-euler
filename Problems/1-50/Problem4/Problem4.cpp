//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include "generics.hpp"

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::is_palindrome;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    numtype largest_palindrome = 0;

    for (numtype i = 100; i < 1000; i++) {
        for (numtype j = i; j < 1000; j++) {
            numtype n = i * j;
            if (n > largest_palindrome && is_palindrome(n))
                largest_palindrome = n;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The largest palindrome made from the product of two 3-digit numbers is " << largest_palindrome << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}