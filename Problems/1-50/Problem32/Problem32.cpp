//
// Created by Alex Beccaro on 18/12/17.
//

#include <iostream>
#include <unordered_set>
#include <generics.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using generics::digits;

using numtype = unsigned long;

numtype combine(numtype a, numtype b) {
    numtype times = 1;
    while (times <= b)
        times *= 10;
    return a*times + b;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    unordered_set<numtype> pandigital_products;
    const vector<unsigned short> all_digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (numtype i = 2; i <= 98; i++)
        for (numtype j = 123; j <= 4987; j++) {
            numtype prod = i * j;
            numtype combined = combine(combine(prod, j), i);

            vector<unsigned short> digs = digits(combined);
            sort(digs.begin(), digs.end());
            if (digs == all_digits)
                pandigital_products.insert(prod);
        }

    numtype result = 0;
    for (numtype n : pandigital_products)
        result += n;


    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 "
         << "pandigital is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}