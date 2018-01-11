//
// Created by Alex Beccaro on 04/01/18.
//

#include <iostream>
#include <vector>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;

using numtype = unsigned long;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    numtype max = 0;
    const vector<unsigned int> all_digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (numtype i = 1; i < 10000; i++) {
        vector<unsigned int> product_digits;

        for (numtype j = 1; product_digits.size() < 9; j++) {
            vector<unsigned int> partial_product = digits(i * j);

            product_digits.insert(product_digits.end(), partial_product.begin(), partial_product.end());
        }

        numtype product = from_digits<numtype>(product_digits);
        sort(product_digits.begin(), product_digits.end());

        if (product_digits == all_digits && product > max)
            max = product;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The largest 1 to 9 pandigital number that can be formed as the concatenated product of an integer with "
         << "(1,2, ... , n) where n > 1 is " << max << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}