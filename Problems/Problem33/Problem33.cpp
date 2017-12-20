//
// Created by Alex Beccaro on 19/12/17.
//

#include <iostream>
#include <generics.hpp>
#include <unordered_set>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;

using numtype = unsigned int;

/**
 * Checks if given fraction (n/d) is digit cancelling. Both n and d are supposed to have 2 digits.
 * @param n The numerator
 * @param d The denominator
 * @return true if fraction is digit cancelling, false otherwise
 */
bool is_digit_cancelling(numtype n, numtype d) {
    numtype n1 = n / 10;
    numtype n2 = n % 10;
    numtype d1 = d / 10;
    numtype d2 = d % 10;
    numtype gcd_nd = gcd(n, d);

    return (n1 == d1 && n / gcd_nd == n2 / gcd(n2, d2) && d / gcd_nd == d2 / gcd(n2, d2)) ||
           (n1 == d2 && n / gcd_nd == n2 / gcd(n2, d1) && d / gcd_nd == d1 / gcd(n2, d1)) ||
           (n2 == d1 && n / gcd_nd == n1 / gcd(n1, d2) && d / gcd_nd == d2 / gcd(n1, d2)) ||
           (n2 == d2 && n / gcd_nd == n1 / gcd(n1, d1) && d / gcd_nd == d1 / gcd(n1, d1));

}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    numtype num_product = 1;
    numtype den_product = 1;

    for (numtype n = 10; n < 100; n++)
        for (numtype d = n + 1; d < 100; d++)
            if (d % 10 != 0 && is_digit_cancelling(n, d)) {
                num_product *= n;
                den_product *= d;
            }

    numtype result = den_product / gcd(num_product, den_product);

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The denominator of the product of all digit cancelling fractions is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}