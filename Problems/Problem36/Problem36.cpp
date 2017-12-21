//
// Created by Alex Beccaro on 21/12/17.
//

#include <iostream>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 1000000;

    timer::time_point start = timer::now();

    numtype result = 0;

    for (numtype i = 1; i < UPPER_BOUND; i++) {
        if (is_palindrome(i)) {
            vector<unsigned short> digs = to_base(i, 2);
            vector<unsigned short> rev_digs(digs.size());

            reverse_copy(digs.begin(), digs.end(), rev_digs.begin());

            if (digs == rev_digs)
                result += i;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all numbers which are palindromic in base 10 and base 2 is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}